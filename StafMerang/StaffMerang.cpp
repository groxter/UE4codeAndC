// Fill out your copyright notice in the Description page of Project Settings.

#include "StaffMerang.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"

// Sets default values
AStaffMerang::AStaffMerang()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Staf"));
	timeLine = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimeLine"));

	InterpFunction.BindFunction(this, FName("TimeLineFloatReturn"));
	TimeLineFinish.BindFunction(this, FName("OnTimeLineFinish"));

	// goes through the curve smooth avoid lower or higer levels
	ZOffSet = 50.f;
}

// Called when the game starts or when spawned
void AStaffMerang::BeginPlay()
{
	Super::BeginPlay();
	
	if (FCurve)
	{
		timeLine->AddInterpFloat(FCurve, InterpFunction, FName("Alpha"));
		timeLine->SetTimelineFinishedFunc(TimeLineFinish);

		// Vector
		Start = GetActorLocation();
		End = FVector(Start.X, Start.Y, Start.Z + ZOffSet);

		//TimeLine Settings
		timeLine->SetLooping(false);
		timeLine->SetIgnoreTimeDilation(true);

		timeLine->Play();
	}
}

// Called every frame
void AStaffMerang::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newRot = GetActorRotation();
	newRot.Yaw += 1.f;
	SetActorRotation(newRot);
}

void AStaffMerang::TimeLineFloatReturn(float value)
{
	SetActorLocation(FMath::Lerp(Start, End, value));
}

void AStaffMerang::OnTimeLineFinish()
{
	if (timeLine->GetPlaybackPosition() == 0.0f)
	{
		timeLine->Play();
	}
	else
	{
		timeLine->Reverse();
	}
}

