// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnerManager.generated.h"

class ABaseEnemyCharacter;
class AMyPlayerController;
class AEnemySpawner;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveChangedSignature, int, Wave);

UCLASS()
class UNREALTOPDOWN_API AEnemySpawnerManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnWaveChangedSignature OnWaveChanged;
	AMyPlayerController* MyPlayerController;

protected:
	//Enemies Wave Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	TArray<TSubclassOf<ABaseEnemyCharacter>> EnemyArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float DamageGrow = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float HealthGrow = 50.f;

	//Wave Settings
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
	void Wave();

	void SpawnEnemy(AEnemySpawner* PickedSpawner);
private:
	int PickRandomEnemy() const;

};
