// Fill out your copyright notice in the Description page of Project Settings.


#include "Management/EnemySpawnerManager.h"

#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Objects/EnemySpawner.h"

// Sets default values
AEnemySpawnerManager::AEnemySpawnerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawnerManager::BeginPlay()
{
	Super::BeginPlay();
	
	WaveNumber = 0;

	StartSpawning = true;
}

// Called every frame
void AEnemySpawnerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (StartSpawning)
	{
		StartWave();
		StartSpawning = false;
	}

	if (!WaveStarted) return;

	CurrentTimeBetweenSpawns -= DeltaTime;

	if (CurrentTimeBetweenSpawns <= 0 && SpawnedEnemies < EnemiesToSpawn)
	{
		if (Spawners.Num() == 0) return;
		
		int32 Index = FMath::RandRange(0, Spawners.Num() - 1);
		AEnemySpawner* PickedSpawner = Spawners[Index];

		if (IsValid(PickedSpawner))
		{
			PickedSpawner->SpawnEnemy();
		}
		
		SpawnedEnemies++;
		CurrentTimeBetweenSpawns = TimeBetweenSpawns;
	}
}

void AEnemySpawnerManager::StartWave()
{
	if (Spawners.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawners not initialized"));
		return;
	}

	WaveNumber++;
	CurrentTimeBetweenSpawns = TimeBetweenSpawns;
	SpawnedEnemies = 0;
	
	WaveStarted = true;
	
}

