// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnerManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScoreChangedSignature, int32, Score, int, WaveNumber);

class APlayerTwinStickCharacter;
class AMyPlayerController;
class AEnemySpawner;

UCLASS()
class UNREALTOPDOWN_API AEnemySpawnerManager : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnScoreChangedSignature OnScoreChanged;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Settings")
	int WaveNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int EnemiesToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float TimeBetweenSpawns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float TimeBetweenWaves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawners")
	TArray<AEnemySpawner*> Spawners;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Settings")
	bool WaveStarted = false;

private:

	float CurrentTimeBetweenSpawns;
	int32 SpawnedEnemies;
	int32 TotalEnemiesKilled;
	bool StartSpawning;
	
	APawn* Player;
	AMyPlayerController* PlayerController;

public:	
	// Sets default values for this actor's properties
	AEnemySpawnerManager();

	void AddTotalEnemiesKilled();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartWave();
	void Wave();

private:
	void SetPlayerActor();
};
