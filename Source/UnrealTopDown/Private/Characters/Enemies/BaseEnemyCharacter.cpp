// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/BaseEnemyCharacter.h"

#include "Characters/PawnState.h"
#include "Characters/Enemies/EnemyAIController.h"
#include "Characters/Enemies/EnemyAttributes.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	Attributes = CreateDefaultSubobject<UEnemyAttributes>(TEXT("Attributes"));
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PawnState = PawnState::Moving;
}

void ABaseEnemyCharacter::GetDamage_Implementation(float amount)
{
	UE_LOG(LogTemp, Warning, TEXT("Amount: %f"), amount);
	
	float Health = Attributes->GetHealth();
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
	Health -= amount;
	
	//UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);

	if (Health <= 0)
	{
		Destroy();
	}
	else
	{
		Attributes->SetHealth(Health);
	}
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
}

