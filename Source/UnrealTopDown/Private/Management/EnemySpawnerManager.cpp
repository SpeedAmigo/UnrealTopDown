// Fill out your copyright notice in the Description page of Project Settings.


#include "Management/EnemySpawnerManager.h"
#include "Characters/Player/MyPlayerController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Objects/EnemySpawner.h"
#include "UI/CountDownUI.h"
#include "UI/PlayerHUD.h"

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

	MyPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	OnWaveChanged.AddDynamic(MyPlayerController->GetPlayerHUD(), &UPlayerHUD::UpdateWave);

	for (auto EnemySpawner : Spawners)
	{
		EnemySpawner->SetDefaults(EnemyArray, HealthGrow, DamageGrow, SpeedGrow);
		OnSpawnEnemies.AddDynamic(EnemySpawner, &AEnemySpawner::SpawnEnemy);
	}

	WaveNumber = 0;
	StartSpawning = true;

	if (OnWaveChanged.IsBound())
	{
		OnWaveChanged.Broadcast(WaveNumber);
	}
}

void AEnemySpawnerManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (auto Spawner : Spawners)
	{
		OnSpawnEnemies.RemoveDynamic(Spawner, &AEnemySpawner::SpawnEnemy);
	}
}


// Called every frame
void AEnemySpawnerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//start game
	if (StartSpawning)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wave timer: %f"), CurrentTimeBetweenWaves)
		if (CountDownUI && CurrentTimeBetweenWaves < 6.f)
		{
			if (!CountDownUI->IsInViewport()) CountDownUI->AddToViewport();
			CountDownUI->UpdateCountdownText(CurrentTimeBetweenWaves);
		}
		CurrentTimeBetweenWaves -= DeltaTime;
		if (CurrentTimeBetweenWaves <= 0) StartWave();
	}

	if (WaveStarted)
	{
		CurrentTimeBetweenSpawns -= DeltaTime;
		if (CurrentTimeBetweenSpawns <= 0) Wave();
	}
}

void AEnemySpawnerManager::Wave()
{
	if (SpawnedEnemies < EnemiesToSpawn){
		if (Spawners.Num() == 0) return;

		//pick random spawner and spawn enemy
		//int32 Index = FMath::RandRange(0, Spawners.Num() - 1);
		//AEnemySpawner* PickedSpawner = Spawners[Index];
		OnSpawnEnemies.Broadcast(WaveNumber);

		SpawnedEnemies++;
		CurrentTimeBetweenSpawns = TimeBetweenSpawns;
	}
	else{
		EnemiesToSpawn += 1;
		TimeBetweenSpawns -= 0.1f;
		WaveStarted = false;

		UE_LOG(LogTemp, Warning, TEXT("Wave Started"))
		CurrentTimeBetweenWaves = TimeBetweenWaves;
		StartSpawning = true;
	}
}

void AEnemySpawnerManager::StartWave()
{
	StartSpawning = false;

	if (Spawners.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawners not initialized"));
		return;
	}

	WaveNumber++;
	CurrentTimeBetweenSpawns = TimeBetweenSpawns;
	SpawnedEnemies = 0;
	
	WaveStarted = true;

	CountDownUI->RemoveFromParent();

	if (OnWaveChanged.IsBound())
	{
		OnWaveChanged.Broadcast(WaveNumber);
	}
}




