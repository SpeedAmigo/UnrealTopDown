// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/EnemySpawner.h"

#include "Characters/Enemies/BaseEnemyCharacter.h"
#include "Characters/Enemies/EnemyAIController.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"

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

int AEnemySpawner::PickRandomEnemy()
{
	if (EnemyArray.Num() == 0) return false;

	return FMath::RandRange(0, EnemyArray.Num() - 1);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::SpawnEnemy()
{
	if (EnemyArray.Num() == 0) return;

	UWorld* World = GetWorld();
	if (!World) return;

	FTransform SpawnTransform = GetActorTransform();
	FVector SpawnLocation = GetActorLocation() + FVector(0, 0, 50.f);
	SpawnTransform.SetLocation(SpawnLocation);
	
	ABaseEnemyCharacter* spawned = World->SpawnActor<ABaseEnemyCharacter>(EnemyArray[PickRandomEnemy()], SpawnTransform);
	
	UE_LOG(LogTemp, Warning, TEXT("EnemySpawned"));
}

