// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/EnemySpawner.h"

#include "Characters/Enemies/BaseEnemyCharacter.h"
#include "Characters/Enemies/EnemyAIController.h"
#include "Characters/Enemies/EnemyAttributes.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Management/EnemySpawnerManager.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::SpawnEnemy(TArray<TSubclassOf<ABaseEnemyCharacter>> EnemyArray, int Wave, float HealthGrow, float DamageGrow)
{

	UWorld* World = GetWorld();
	if (!World) return;

	FTransform SpawnTransform = GetActorTransform();
	FVector SpawnLocation = GetActorLocation() + FVector(0, 0, 50.f);
	SpawnTransform.SetLocation(SpawnLocation);

	ABaseEnemyCharacter* spawned = World->SpawnActor<ABaseEnemyCharacter>(EnemyArray[PickRandomEnemy(EnemyArray)], SpawnTransform);

	UEnemyAttributes* EnemyAttributes = spawned->GetAttributes();
	EnemyAttributes->SetMaxHealth(EnemyAttributes->GetMaxHealth() + (HealthGrow * Wave));
	EnemyAttributes->SetDamage(EnemyAttributes->GetDamage() + (DamageGrow * Wave));

	//UE_LOG(LogTemp, Warning, TEXT("EnemySpawned"));
}

int AEnemySpawner::PickRandomEnemy(const TArray<TSubclassOf<ABaseEnemyCharacter>>& EnemyArray) const
{
	if (EnemyArray.Num() == 0) return false;

	return FMath::RandRange(0, EnemyArray.Num() - 1);
}


