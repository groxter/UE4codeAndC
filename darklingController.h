// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "darklingController.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIAL_API AdarklingController : public AAIController
{
	GENERATED_BODY()

		UPROPERTY(transient)
		TSubobjectPtrDeprecated<class UBlackboardComponent> BlackBoardComp;

	    UPROPERTY(transient)
		TSubobjectPtrDeprecated<class UBehaviourTreeComponent> BehaviourComp;

		virtual void  Possess(class APawn *InPawn);
		void setEnemy(class APawn *InPawn);

		UFUNCTION(BlueprintCallable, Category = Behaviour)
		void searchForEnemy();

protected:

	uint8 EnemyKeyID;
	uint8 EnemyLocationID;
};
