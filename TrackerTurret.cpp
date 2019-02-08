// Fill out your copyright notice in the Description page of Project Settings.

#include "TrackerTurret.h"
#include "Engine/World.h"

// Sets default values
ATrackerTurret::ATrackerTurret()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TrackerEnemy = CreateDefaultSubobject<UStaticMeshComponent>("Tracker");
	
}

// Called when the game starts or when spawned
void ATrackerTurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackerTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(GetActorForwardVector(), 4);
}
// Called to bind functionality to input
void ATrackerTurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Tracking Character
FRotator ATrackerTurret::trackTina(ACharacter* tina)
{
	FRotator rot = FRotationMatrix::MakeFromX(tina->GetActorLocation()).Rotator();
	FRotator yaw = FRotator(0, 0, rot.Yaw);
	FRotator newRot = FMath::RInterpTo(GetActorRotation(), yaw, GetWorld()->GetDeltaSeconds(), 0.0);

	return newRot;
}

