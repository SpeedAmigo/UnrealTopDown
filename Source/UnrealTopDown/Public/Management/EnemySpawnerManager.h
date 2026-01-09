// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnerManager.generated.h"

class AEnemySpawner;

UCLASS()
class UNREALTOPDOWN_API AEnemySpawnerManager : public AActor
{
	GENERATED_BODY()

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

	bool StartSpawning;
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnerManager();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartWave();
};
