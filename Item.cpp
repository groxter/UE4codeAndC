// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject< UStaticMeshComponent >(TEXT("Item"));
	mesh->SetSimulatePhysics(true);
	CollisionChanel = ECollisionChannel::ECC_Visibility;
	trace = 100.f;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Fresult;
	bOnHit = GetWorld()->LineTraceSingleByChannel(Fresult, mesh->GetComponentLocation(), endVector(trace), CollisionChanel, CollisionParams);
	
	if (bOnHit)
	{
		alphaVector = mesh->GetComponentLocation() - Fresult.Location;
		float div = alphaVector.Size() / trace;
		lerp = FMath::Lerp(30000.f, 0.f , div);
		force->AddForce(FVector(Fresult.ImpactNormal.X * lerp, Fresult.ImpactNormal.Y * lerp, Fresult.ImpactNormal.Z * lerp));
		force->SetLinearDamping(1.f);
		force->SetAngularDamping(0.6);
	}
}

void AItem::setTrace(float t)
{
	trace = t;
}

FVector AItem::endVector(float trace)
{
	FVector endVector = { 0.0f ,0.0f ,trace };
	return GetActorLocation() - endVector;
}

// How it would be done by hand
void AItem::lineTraceByChannel(FVector start, FVector end)
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		start,    //start
		end, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);
}

