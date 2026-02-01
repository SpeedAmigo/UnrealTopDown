// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AEnemySpawnerManager;
class ABaseEnemyCharacter;

UCLASS()
class UNREALTOPDOWN_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
protected:

	TArray<TSubclassOf<ABaseEnemyCharacter>> EnemyArray;
	float HealthGrow;
	float DamageGrow;
	float SpeedGrow;

public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnEnemy(int Wave);

	void SetDefaults(TArray<TSubclassOf<ABaseEnemyCharacter>> EnemiesToSpawn, float HealthGrowth, float DamageGrowth, float SpeedGrowth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int PickRandomEnemy();
};
