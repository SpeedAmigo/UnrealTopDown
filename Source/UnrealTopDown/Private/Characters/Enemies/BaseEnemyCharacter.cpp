// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/BaseEnemyCharacter.h"

#include "Characters/PawnState.h"
#include "Characters/Enemies/EnemyAIController.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PawnState = PawnState::Moving;
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
}

