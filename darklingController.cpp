// Fill out your copyright notice in the Description page of Project Settings.

#include "Darkling.h"
#include "darklingController.h"
#include "Darkling.h"

AdarklingController::AdarklingController(const class FPostConstructInitializeProperties& PCIP)
	:Super(PCIP)
{
	BlackBoardComp = PCIP.CreateDefaultSubobject< UBlackboardComponent >(this, TEXT("BlackBoardComp"));
	BehaviourComp = PCIP.CreateDefaultSubobject< UBehaviourTreeComponent >(this, TEXT("BehaviourComp"));
}

void AdarklingController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);
	ADarkling* darkling = Cast<ADarkling>(InPawn);
	if (darkling && darkling->darklingBehavior)
	{
		BlackboardComp->InitializeBlackboard(darkling->darklingBehavior->BlackboardAsset);

		EnemyKeyId = BlackBoardComp->GetKeyID("Enemy");
		EnemyLocationId = BlackBoardComp->GetKeyID("Destination");

		BehaviourComp->StartTree(darkling->darklingBehavior);
	}
}

void AdarklingController::setEnemy(class APawn* InPawn)
{
	BlackBoardComp->SetValueAsObject(EnemyKeyID, InPawn);
	BlackBoardComp->SetValueAsVector(EnemyLocationID, InPawn->GetActorLocation());
}

void AdarklingController::searchForEnemy()
{
	APawn* myDarkling = GetPawn();
	if (myDarkling == NULL) return;

	const FVector MyLoc = myDarkling->GetActorLocation();
	float BestDistSq = MAX_FLT;
}