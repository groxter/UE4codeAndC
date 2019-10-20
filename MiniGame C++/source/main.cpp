

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <MMSystem.h>
#include "ParticleSystem.h"

#if defined( NDEBUG )

#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")

#else // defined( NDEBUG )

#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")

#endif // defined( NDEBUG )

#define UNUSED(x) (void)(x)

#define PI_VALUE (3.142f)

typedef sf::Vector2f Float2;
typedef sf::Vector3f Float3;
sf::Shader shaders;
int difficulty = 1;
bool resetTimerFlag = false;

//////////////////////////////////////////////////////////////////////////
// Utility functions

void DebugLog(const char* msg, ...)
{
	char temp[4096];

	va_list ap;
	va_start(ap, msg);
	vsnprintf_s(temp, 4096-1, msg, ap);
	va_end(ap);

	OutputDebugStringA(temp);
}

//////////////////////////////////////////////////////////////////////////

float Clamp(float x, float lower, float upper)
{
	return fmin(upper, fmax(x, lower));
}

//////////////////////////////////////////////////////////////////////////

float LengthSq(Float2 v)
{
	return ((v.x * v.x) + (v.y * v.y));
}

//////////////////////////////////////////////////////////////////////////

float Length(Float2 v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}

//////////////////////////////////////////////////////////////////////////

Float2 Normalized(Float2 v)
{
	float len = Length(v);
	return Float2(v.x / len, v.y / len);
}

//////////////////////////////////////////////////////////////////////////

float Dot(Float2 v1, Float2 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

//////////////////////////////////////////////////////////////////////////

Float2 Rotate(Float2 v, float angleRadians)
{
	return Float2(
			v.x * cos(angleRadians) - v.y * sin(angleRadians),
			v.x * sin(angleRadians) + v.y * cos(angleRadians)
		);
}

//////////////////////////////////////////////////////////////////////////

float RadiansToDegrees(float deg)
{
	return deg * (180.0f / PI_VALUE);
}

//////////////////////////////////////////////////////////////////////////

float DegreesToRadians(float deg)
{
	return deg * (PI_VALUE / 180.0f);
}

//////////////////////////////////////////////////////////////////////////

float ToAngle(Float2 v)
{
	return atan2f(v.y, v.x);
}

//////////////////////////////////////////////////////////////////////////

// Returns a random value between 0.0f - 1.0f
float FRand()
{
	return ((float)std::rand() / (float)RAND_MAX);
}

//////////////////////////////////////////////////////////////////////////

// Test intersection between a line and circle
bool TestLineToCircle(Float2 p1, Float2 p2, Float2 circleCenter, float circleRadius)
{
	Float2 d = p2 - p1;
	Float2 f = circleCenter - p1;

	// find the closest point between the line and the circle center
	Float2 du = Normalized(d);
	float proj = Dot(f, du);

	Float2 closest;

	if (proj < 0.0f)
	{
		closest = p1;
	}
	else if (proj > Length(d))
	{
		closest = p2;
	}
	else
	{
		Float2 projV = du * proj;
		closest = projV + p1;
	}

	Float2 closestDiff = circleCenter - closest;
	float closestLen = Length(closestDiff);

	if (closestLen > circleRadius)
	{
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
// Game resources

struct Resources
{
	sf::Texture mBackgroundTex;
	sf::Texture mPlayerTex;
	sf::Texture mEnemyTex;
	sf::Font	mMainFont;
	sf::Shader	mPostProShader;
};

//////////////////////////////////////////////////////////////////////////

bool LoadResources(Resources& r)
{
	bool success = true;

	success &= r.mBackgroundTex.loadFromFile("../assets/patchygrass_1.jpg");
	success &= r.mPlayerTex.loadFromFile("../assets/player.png");
	success &= r.mEnemyTex.loadFromFile("../assets/enemy.png");
	success &= r.mMainFont.loadFromFile("../assets/RussoOne-Regular.ttf");
	success &= r.mPostProShader.loadFromFile("../assets/shaders/postpro.vert", "../assets/shaders/postpro.frag");

	return success;
}

//////////////////////////////////////////////////////////////////////////
// Particle systems

//////////////////////////////////////////////////////////////////////////
// Blood

struct BloodParticle : public BaseParticle
{
	Float2		mVelocity			= Float2(0.0f, 0.0f);

	sf::Time	mInitialLifetime;
};

struct BloodParticleSpawnParams
{
	Float2	mPos		= Float2(0.0f, 0.0f);
	Float2	mVelocity	= Float2(0.0f, 0.0f);

	float	mSpread		= 0.0f;		// cone angle for emissions
};

ParticleSystem<BloodParticle, BloodParticleSpawnParams> gParticlesBlood(5000);

//////////////////////////////////////////////////////////////////////////

void InitBloodParticle(BloodParticle& particle, BloodParticleSpawnParams const& params)
{
	// give a random velocity and lifetime to the particle
	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = 0.0f + FRand() * 500.f;

	particle.mVelocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	particle.mInitialLifetime = particle.mLifetime = sf::milliseconds((std::rand() % 500) + 20000);
	particle.mSize = FRand() * 20.0f;
	particle.mColor = sf::Color(128 + (std::rand() % 128), 0 + (std::rand() % 30), 0 + (std::rand() % 30), 255);

	// skew velocity in direction of shot
	Float2 dir = Normalized(params.mVelocity);
	dir = Rotate(dir, DegreesToRadians(params.mSpread * (FRand() - 0.5f)));

	particle.mVelocity = (dir * speed);
	particle.mPos = params.mPos;
}

//////////////////////////////////////////////////////////////////////////

void UpdateBloodParticle(BloodParticle& particle, sf::Time elapsed)
{
	particle.mLifetime -= elapsed;

	float a = std::max(particle.mLifetime / particle.mInitialLifetime, 0.0f);
	particle.mColor.a = static_cast<sf::Uint8>(a * 255);

	particle.mPos += particle.mVelocity * elapsed.asSeconds();

	sf::Time age = particle.mInitialLifetime - particle.mLifetime;

	if (age.asSeconds() > 0.2f)
	{
		particle.mVelocity = Float2(0.0f, 0.0f);
	}
}

//////////////////////////////////////////////////////////////////////////

void SpawnBloodParticles(Float2 pos, Float2 dir, uint32_t quantity, float spreadAngle)
{
	BloodParticleSpawnParams params = {};

	params.mPos = pos;
	params.mVelocity = dir;
	params.mSpread = spreadAngle;

	gParticlesBlood.Spawn(quantity, params, InitBloodParticle);
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderAllParticles(sf::RenderTexture* renderTex, float dt)
{
	sf::Time elapsed = sf::seconds(dt);
	gParticlesBlood.Update(elapsed);

	renderTex->draw(gParticlesBlood);
}

//////////////////////////////////////////////////////////////////////////
// GAMEPLAY code

struct Bullet
{
	Float2	mPos		= Float2(0.0f, 0.0f);
	Float2	mVelocity	= Float2(0.0f, 0.0f);

	float	mLife		= 0.0f;
};

struct Enemy
{
	Float2 mPos			= Float2(0.0f, 0.0f);
	Float2 mVelocity	= Float2(0.0f, 0.0f);
	Float2 Knockback	= Float2(0.0f, 0.0f);

	float mHealth		= 0.0f;
	float mLastHit		= 0.0f;

	bool reset = false;
};

struct GameState
{
	Float2 mPlayerPos		= Float2(0.0f, 0.0f);
	Float2 mPlayerDir		= Float2(0.0f, 0.0f);
	Float2 mMouseWorldPos	= Float2(0.0f, 0.0f);

	float mPlayerFireCooldown	= 0.0f;
	float mEnemySpawnCounter	= 0.0f;

	int32_t mPlayerScore = 0;

	std::vector<Bullet*> mBullets;
	std::vector<Enemy*> mEnemies;
};

//////////////////////////////////////////////////////////////////////////
// Gameplay parameters

static Float2 sWindowSize = Float2(1280.0f, 720.0f);

static const float sPlayerSpeed				= 200.0f;
static const float sPlayerFireDelay			= 0.10f;
static const float sPlayerBulletSpeed		= 1000.0f;
static const float sPlayerBulletLife		= 0.5f;
static const float sPlayerBulletSize		= 4.0f;

static const float sEnemyTowardsPlayerForce = 10000.0f;
static const float sEnemyMinPlayerDistance	= 80.0f;
static const float sEnemySpawnTime			= 3.0f;
static const float sEnemyMaxVelocity		= 100.0f;
static const float sEnemyKnockbackDecay		= 0.8f;

//////////////////////////////////////////////////////////////////////////

void resetGame(GameState* gameState)
{
	gameState->mPlayerPos = Float2(0.0f, 0.0f);
	gameState->mPlayerDir = Float2(0.0f, 0.0f);
	gameState->mMouseWorldPos = Float2(0.0f, 0.0f);
	resetTimerFlag = true;

	for (unsigned x = 0; x < gameState->mEnemies.size(); x++) // O(n) complexity
	{
		Enemy* enemy = gameState->mEnemies.at(x);
		enemy->reset = true;
		enemy->mHealth = 0.0f;
	}

}

Float2 EnemyMovementForce(GameState* gameState, Enemy* enemy)
{
	Float2 enemyToPlayer = gameState->mPlayerPos - enemy->mPos;
	Float2 force = Float2(0.0f, 0.0f);

	// head towards player
	if (Length(enemyToPlayer) > sEnemyMinPlayerDistance)
	{
		force += Normalized(enemyToPlayer) * sEnemyTowardsPlayerForce;
	}
	else
	{
		// don't get too close!
		if (Length(enemyToPlayer) > FLT_MIN)
		{
			//force += -Normalized(enemyToPlayer) * powf(sEnemyMinPlayerDistance - Length(enemyToPlayer), 3.0f);
			resetGame(gameState);
			
		}
		else
		{
			force += Float2(0.0f, 1.0f) * powf(sEnemyMinPlayerDistance, 3.0f);
		}
	}

	// keep away from other enemies
	for (uint32_t i = 0; i < gameState->mEnemies.size(); ++i)
	{
		// ignore self
		if (enemy != gameState->mEnemies[i])
		{
			Float2 enemyToEnemy = enemy->mPos - gameState->mEnemies[i]->mPos;

			if (Length(enemyToEnemy) < 100.0f)
			{
				force += Normalized(enemyToEnemy) * (100.0f - Length(enemyToEnemy)) * 1000.0f;
			}
		}
	}

	return force;
}

//////////////////////////////////////////////////////////////////////////

void HitEnemy(Enemy* e, Bullet* b)
{
	UNUSED(b);

	e->mHealth -= 10.0f;

	// knockback
	Float2 knockback = Normalized(b->mVelocity) * 100.0f;
	e->Knockback += knockback;

	// flash enemy
	e->mLastHit = 0.0f;
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderLevel(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, float dt)
{
	UNUSED(gameState);
	UNUSED(dt);

	Float2 texSize = (Float2)resources->mBackgroundTex.getSize();

	sf::Sprite s(resources->mBackgroundTex);

	s.setOrigin(texSize / 2.0f);
	s.setColor(sf::Color(80, 80, 80));
	s.setPosition(sf::Vector2f(0.0f, 0.0f));

	sf::View view(sf::Vector2f(0.0f, 0.0f), sWindowSize);
	renderTex->setView(view);
	
	renderTex->draw(s);
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderPlayer(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, float dt)
{
	Float2 playerVelocity = Float2(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		playerVelocity.y -= 1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		playerVelocity.y += 1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{	
		playerVelocity.x += 1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{	
		playerVelocity.x -= 1.0f;
	}

	// ensure the player doesn't go faster diagonally
	if (LengthSq(playerVelocity) > 1.0f)
	{
		playerVelocity = Normalized(playerVelocity);
	}

	// move the player
	gameState->mPlayerPos += playerVelocity * sPlayerSpeed * dt;

	// point the player at the mouse cursor
	Float2 playerToMouse = gameState->mMouseWorldPos - gameState->mPlayerPos;
	gameState->mPlayerDir = Normalized(playerToMouse);

	// draw the player
	sf::Sprite playerSprite(resources->mPlayerTex);

	playerSprite.setOrigin((Float2)resources->mPlayerTex.getSize() * 0.5f);
	playerSprite.setPosition(gameState->mPlayerPos.x, gameState->mPlayerPos.y);
	playerSprite.setRotation(RadiansToDegrees(ToAngle(gameState->mPlayerDir)));

	renderTex->draw(playerSprite);

	// player firing

	gameState->mPlayerFireCooldown -= dt;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (gameState->mPlayerFireCooldown <= 0.0f)
		{
			gameState->mPlayerFireCooldown = sPlayerFireDelay;

			Bullet* bullet = new Bullet();
			gameState->mBullets.push_back(bullet);
			
			PlaySound(TEXT("..\\assets\\gunshot6.wav"), NULL, SND_ASYNC); // playing sound effect

			bullet->mLife = sPlayerBulletLife;
			bullet->mPos = gameState->mPlayerPos;
			bullet->mVelocity = gameState->mPlayerDir * sPlayerBulletSpeed;
		}
	}
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderBullets(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, float dt)
{
	UNUSED(resources);

	// update and draw player bullets
	sf::CircleShape bulletShape(sPlayerBulletSize);
	bulletShape.setOrigin(sPlayerBulletSize / 2.0f, sPlayerBulletSize / 2.0f);

	for (std::vector<Bullet*>::iterator it = gameState->mBullets.begin(); it != gameState->mBullets.end(); )
	{
		Bullet* bullet = *it;
		Float2 oldPos = bullet->mPos;
		Float2 newPos = oldPos + bullet->mVelocity * dt;

		bullet->mLife -= dt;

		bool expireBullet = false;

		if (bullet->mLife <= 0.0f)
		{
			expireBullet = true;
		}
		else
		{
			// only player shooting at the moment so just test against enemies
			for (uint32_t j = 0; j < gameState->mEnemies.size(); ++j)
			{
				Float2 enemyPos = gameState->mEnemies[j]->mPos;
				float enemyRadius = 20.0f;

				if (TestLineToCircle(oldPos, newPos, enemyPos, enemyRadius))
				{
					HitEnemy(gameState->mEnemies[j], bullet);
					expireBullet = true;
					break;
				}
			}

			bullet->mPos = newPos;

			bulletShape.setPosition(bullet->mPos.x, bullet->mPos.y);
			renderTex->draw(bulletShape);
		}

		if (expireBullet)
		{
			// bullet has expired so swap it with the end of the list and reduce the count by one
			delete bullet;
			it = gameState->mBullets.erase(it);
		}
		else
		{
			++it;
		}
	}
}


//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderEnemies(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, float dt)
{
	bool resetPoints = false;

	for (std::vector<Enemy*>::iterator it = gameState->mEnemies.begin(); it != gameState->mEnemies.end(); )
	{
		Enemy* enemy = *it;

		if (enemy->mHealth <= 0.0f)
		{
			
			// splat away from player because we don't know where the damage came from here
			Float2 splatDir = enemy->mPos - gameState->mPlayerPos;
			(enemy->reset == false) ? SpawnBloodParticles(enemy->mPos, Normalized(splatDir), 100, 50.0f) : resetPoints = true;

			delete enemy;
			it = gameState->mEnemies.erase(it);

			if (resetPoints)
			{
				gameState->mPlayerScore = 0;
			}
			else {
				PlaySound(NULL, NULL, SND_ASYNC);
				PlaySound(TEXT("..\\assets\\die.wav"), NULL, SND_ASYNC);
				gameState->mPlayerScore += 10;
			}

			

			continue;
		}
		else
		{
			if (enemy->mLastHit == 0.0f)
			{
				Float2 splatDir = enemy->mPos - gameState->mPlayerPos;
				SpawnBloodParticles(enemy->mPos, Normalized(splatDir), std::rand() % 10, 20.0f);
			}

			// process movement

			enemy->mVelocity += EnemyMovementForce(gameState, enemy) * dt;


			if (LengthSq(enemy->mVelocity) > (sEnemyMaxVelocity * sEnemyMaxVelocity))
			{
				enemy->mVelocity = Normalized(enemy->mVelocity) * sEnemyMaxVelocity;
			}

			enemy->mVelocity += enemy->Knockback;
			enemy->Knockback *= sEnemyKnockbackDecay;

			
			switch (difficulty)
			{
				case 1: enemy->mPos += enemy->mVelocity * dt; // Easy
					break;

				case 2: enemy->mPos += enemy->mVelocity * 0.03f; // Medium
					break;

				case 3: enemy->mPos += enemy->mVelocity * 0.05f; // Hard
					break;
			}
					

			// Render them

			sf::Sprite playerSprite(resources->mEnemyTex);

			playerSprite.setOrigin((Float2)resources->mEnemyTex.getSize() * 0.5f);
			playerSprite.setPosition(enemy->mPos.x, enemy->mPos.y);

			// flash for a 50ms when hit
			sf::Color color = (enemy->mLastHit < 0.05f) ? sf::Color::Red : sf::Color::Magenta;
			playerSprite.setColor(color);

			enemy->mLastHit += dt;

			renderTex->draw(playerSprite);

			++it;
		}	
	}

	// spawn any enemies?
	gameState->mEnemySpawnCounter -= dt;

	if (gameState->mEnemySpawnCounter < 0.0f)
	{
		
		gameState->mEnemySpawnCounter = sEnemySpawnTime;

		Enemy* enemy = new Enemy();
		gameState->mEnemies.push_back(enemy);
		PlaySound(TEXT("..\\assets\\spawn.wav"), NULL, SND_ASYNC);

		enemy->mHealth = 100.0f;
		//enemy->mPos = Float2(0.0f, 0.0f);		// TODO: random offscreen pos

		Float2 s = (Float2)renderTex->getSize();
		float f = (float)rand() / RAND_MAX;
		enemy->mPos = Float2(f * s.x, f + s.y);
		
		enemy->mLastHit = 1.0f;
	}
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderPPFX(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, sf::RenderWindow* window, float dt)
{
	UNUSED(gameState);
	UNUSED(dt);
	
	resources->mPostProShader.setParameter("texture", renderTex->getTexture());

	// Take RenderTexture as a texture and convert to Sprite to draw back to window with post pro shader applied.

	sf::Sprite fullScreenSprite = sf::Sprite(renderTex->getTexture());

	Float2 vpSize = window->getView().getSize();
	fullScreenSprite.setOrigin((float)vpSize.x / 2, (float)vpSize.y / 2);

	// Flip Vertically
	fullScreenSprite.setScale(sf::Vector2f(1.0f, -1.0f)); 

	window->draw(fullScreenSprite, &resources->mPostProShader);
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRenderUI(GameState* gameState, Resources* resources, sf::RenderWindow* window, float dt)
{
	UNUSED(gameState);
	UNUSED(dt);

	Float2 vpSize = window->getView().getSize();
	
	// draw UI
	sf::Text text;
	text.setFont(resources->mMainFont);
	text.setCharacterSize(32);
	text.setStyle(sf::Text::Bold);

	//text.setString("TOP LEFT");
	//text.setPosition(-vpSize.x/2.0f, -vpSize.y/2.0f - 10);
	//window->draw(text);
	//
	//text.setString("TOP RIGHT");
	//text.setPosition(vpSize.x/2.0f - text.getLocalBounds().width, -vpSize.y/2.0f - 10);
	//window->draw(text);
	//
	//text.setString("BOTTOM LEFT");
	//text.setPosition(-vpSize.x/2.0f, vpSize.y/2.0f - 32);
	//window->draw(text);
	//
	//text.setString("BOTTOM RIGHT");
	//text.setPosition(vpSize.x/2.0f - text.getLocalBounds().width, vpSize.y/2.0f - 32);
	//window->draw(text);

	text.setPosition(window->getView().getCenter().x, window->getView().getCenter().y - vpSize.y / 2.0f - 10);
	text.setString("SCORE: " + std::to_string((_Longlong)gameState->mPlayerScore));

	window->draw(text);
}

//////////////////////////////////////////////////////////////////////////

void UpdateAndRender(GameState* gameState, Resources* resources, sf::RenderTexture* renderTex, sf::RenderWindow* window, float dt)
{
	dt = (dt > 0.01666f ? 0.01666f : dt);

	gameState->mMouseWorldPos = renderTex->mapPixelToCoords(sf::Mouse::getPosition(*window));

	UpdateAndRenderLevel(gameState, resources, renderTex, dt);
	UpdateAndRenderAllParticles(renderTex, dt);
	UpdateAndRenderPlayer(gameState, resources, renderTex, dt);
	UpdateAndRenderBullets(gameState, resources, renderTex, dt);
	UpdateAndRenderEnemies(gameState, resources, renderTex, dt);
	UpdateAndRenderPPFX(gameState, resources, renderTex, window, dt);
	UpdateAndRenderUI(gameState, resources, window, dt);

}

sf::Texture loadShaders()
{

	sf::Texture lightTexture;
	if (!lightTexture.loadFromFile("..\\assets\\shaders\\postpro.vert")) {
		
	}
	return lightTexture;

}

//////////////////////////////////////////////////////////////////////////

int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow
	)
{
	UNUSED(hInstance);
	UNUSED(hPrevInstance);
	UNUSED(lpCmdLine);
	UNUSED(nCmdShow);

	sf::RenderWindow window(sf::VideoMode((uint32_t)sWindowSize.x, (uint32_t)sWindowSize.y), "d3t Banzai!");
	window.setVerticalSyncEnabled(true);

	sf::View view(Float2(0.0f, 0.0f), sWindowSize);
	window.setView(view);

	sf::BlendMode blendMode(
		sf::BlendMode::Factor::Zero,              // color src
		sf::BlendMode::Factor::DstColor,          // color dst
		sf::BlendMode::Equation::Add,             // color eq
		sf::BlendMode::Factor::Zero,              // alpha src
		sf::BlendMode::Factor::OneMinusSrcAlpha,  // alpha dst
		sf::BlendMode::Equation::Add);            // alpha eq

	sf::RenderTexture renderTexture;
	renderTexture.create(100, 100);

	sf::Sprite light0(loadShaders());
	sf::Sprite light1(loadShaders());

	// initialise gamesate to 0
	GameState gameState = {};
	
	Resources resources;

	
	if (!LoadResources(resources))
	{
		DebugLog("Failed to load resources!\n");

		return -1;
	}

	sf::Clock clock;
	
	sf::RenderTexture renderTex;
	renderTex.create((uint32_t)sWindowSize.x, (uint32_t)sWindowSize.y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				sWindowSize = Float2((float)event.size.width, (float)event.size.height);

				view.setSize(sWindowSize);
				window.setView(view);
			}
		}

		if(clock.getElapsedTime().asSeconds() >= 25 && clock.getElapsedTime().asSeconds() <= 50) difficulty = 2;
		if(clock.getElapsedTime().asSeconds() > 50) difficulty = 3;
		
		sf::Time frameTime = clock.getElapsedTime();
		
		if (resetTimerFlag)
		{
			difficulty = 1;
			clock.restart();
			resetTimerFlag = false;
		}
		//clock.restart();
		
		renderTexture.clear();
		renderTexture.draw(light0, blendMode);
		renderTexture.draw(light1, blendMode);
		renderTexture.display();

		sf::Sprite night(renderTexture.getTexture());

		//float luminosity = 200.0f;
		//night.setColor(sf::Color(10.0f, 10.0f, 10.0f, luminosity));


		window.clear();
		
		
		UpdateAndRender(&gameState, &resources, &renderTex, &window, frameTime.asSeconds());
		//window.draw(night);
		window.display();

	}

	return 0;
}