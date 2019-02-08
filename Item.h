// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FIRSTPERSONGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void lineTraceByChannel(FVector start, FVector end);
	float lerp;

	UFUNCTION()
	void setTrace(float t);

	UFUNCTION()
	FVector endVector(float trace);

	UPROPERTY()
	FVector alphaVector;

	UPROPERTY()
	UPrimitiveComponent* force;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY()
	FHitResult Fresult;

	UPROPERTY(EditAnywhere)
	float trace;

	UPROPERTY()
	bool bOnHit;

private:

	ECollisionChannel CollisionChanel;
	FCollisionQueryParams CollisionParams;
};
