// Fill out your copyright notice in the Description page of Project Settings.
// Once the staf is thrown through the player it will spawn this actor from the player's socket and it will wait several seconds to come back to the player through a traced line.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaffMerang.generated.h"

UCLASS()
class PROGRAMMING_API AStaffMerang : public AActor
{
	GENERATED_BODY()

	class UTimelineComponent* timeLine;

public:	
	// Sets default values for this actor's properties
	AStaffMerang();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, Category = "Time_Line")
		class UCurveFloat* FCurve;

	UPROPERTY()
		FVector Start; // actual location of the staf.

	UPROPERTY()
		FVector End; // The hand socket location of the player.

	UPROPERTY(EditAnywhere, Category = "Time_Line")
		float ZOffSet;

	/** Delegate fucntion to be linked with this TimeLineFloatReturn */
	FOnTimelineFloat InterpFunction{};

	/** Delegate function to be linked with OnTimeLineFinish */
	FOnTimelineEvent TimeLineFinish{};
	
	UFUNCTION()
		void TimeLineFloatReturn(float value);

	UFUNCTION()
		void OnTimeLineFinish();
};
