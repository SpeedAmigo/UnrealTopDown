// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/BaseEnemyCharacter.h"

#include "Characters/PawnState.h"
#include "Characters/Enemies/EnemyAIController.h"
#include "Characters/Enemies/EnemyAttributes.h"
#include "Characters/Enemies/EnemyDrop.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	Attributes = CreateDefaultSubobject<UEnemyAttributes>(TEXT("Attributes"));
	EnemyDrop = CreateDefaultSubobject<UEnemyDrop>(TEXT("EnemyDrop"));
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PawnState = PawnState::Moving;
}

void ABaseEnemyCharacter::GetDamage_Implementation(float amount)
{
	float Health = Attributes->GetHealth();
	Health -= amount;
	
	if (Health <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Died!"))
		if (EnemyDrop)
		{
			EnemyDrop->DropItem();
		}
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

