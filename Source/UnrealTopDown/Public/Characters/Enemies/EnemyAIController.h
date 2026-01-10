// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class ABaseEnemyCharacter;
class UBehaviorTree;
class UBlackboardComponent;
class UBehaviorTreeComponent;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	//void GetHit();

protected:
	virtual void BeginPlay() override;

	bool InitializeBlackboard();

	UPROPERTY()
	ABaseEnemyCharacter* EnemyPawn;

	UPROPERTY(EditDefaultsOnly, Category = "BehaviourTree")
	UBehaviorTree* BehaviorTreeAsset;

	UPROPERTY(Transient)
	UBlackboardComponent* BlackboardComp;
	
	UPROPERTY(VisibleAnywhere, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

	// Blackboard key names
	static const FName CanSeePlayer;
	static const FName TargetActor;

	// Perception callback
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};