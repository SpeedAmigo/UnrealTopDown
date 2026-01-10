// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Enemies/EnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/PawnState.h"
#include "Characters/Enemies/BaseEnemyCharacter.h"
#include "Misc/LowLevelTestAdapter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"

const FName AEnemyAIController::CanSeePlayer(TEXT("CanSeePlayer"));
const FName AEnemyAIController::TargetActor(TEXT("TargetActor"));

AEnemyAIController::AEnemyAIController()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	SightConfig->SightRadius = 1000.f;
	SightConfig->LoseSightRadius = 1100.f;
	SightConfig->PeripheralVisionAngleDegrees = 90.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	
	UE_LOG(LogTemp, Log, TEXT("SightRadius = %f (cm), LoseSightRadius = %f (cm)"), SightConfig->SightRadius, SightConfig->LoseSightRadius);
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	EnemyPawn = Cast<ABaseEnemyCharacter>(GetPawn());
	
	if (BehaviorTreeAsset)
	{
		InitializeBlackboard();
		RunBehaviorTree(BehaviorTreeAsset);
	}
}

bool AEnemyAIController::InitializeBlackboard()
{
	if (BehaviorTreeAsset && BehaviorTreeAsset->BlackboardAsset)
	{
		UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BlackboardComp);
		return true;
	}
	return false;
}

/*void AEnemyAIController::GetHit()
{
	if (!BlackboardComp) return;

	AActor* Target = Cast<AActor>(
		BlackboardComp->GetValueAsObject(TargetActor)
	);
	
	if (Target)
	{
		if (EnemyPawn)
		{
			EnemyPawn->PawnState = PawnState::InCombat;
		}
	}
	else
	{
		if (EnemyPawn)
		{
			EnemyPawn->PawnState = PawnState::Moving;
		}
	}
}*/

void AEnemyAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!BlackboardComp) return;

	const bool bSensed = Stimulus.WasSuccessfullySensed();
	BlackboardComp->SetValueAsBool(CanSeePlayer, bSensed);

	if (bSensed)
	{
		BlackboardComp->SetValueAsObject(TargetActor, Actor);
		BlackboardComp->SetValueAsBool(CanSeePlayer, true);
		UE_LOG(LogTemp, Display, TEXT("Sensed Player"));

		if (EnemyPawn)
		{
			EnemyPawn->PawnState = PawnState::InCombat;
		}
	}
	else
	{
		BlackboardComp->SetValueAsObject(TargetActor, nullptr);
		
		if (EnemyPawn)
		{
			EnemyPawn->PawnState = PawnState::Moving;
		}
		
		UE_LOG(LogTemp, Display, TEXT("Cannot see the player"));
	}
}