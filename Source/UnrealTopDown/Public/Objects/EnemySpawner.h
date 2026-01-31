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
	

public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemy(TArray<TSubclassOf<ABaseEnemyCharacter>> EnemyArray, int Wave, float HealthGrow, float DamageGrow);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int PickRandomEnemy(const TArray<TSubclassOf<ABaseEnemyCharacter>>& EnemyArray) const;
};
