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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	TArray<TSubclassOf<ABaseEnemyCharacter>> EnemyArray;

	AEnemySpawnerManager* SpawnerManager;

public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemy();

	void SetSpawnerManager(AEnemySpawnerManager* NewSpawnerManager);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int PickRandomEnemy();
	
};
