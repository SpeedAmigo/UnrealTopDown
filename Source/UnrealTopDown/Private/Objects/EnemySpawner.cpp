// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/EnemySpawner.h"

#include "Characters/Enemies/BaseEnemyCharacter.h"
#include "Characters/Enemies/EnemyAttributes.h"
#include "Engine/World.h"
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

void AEnemySpawner::SpawnEnemy(int Wave)
{

	UWorld* World = GetWorld();
	if (!World) return;

	FTransform SpawnTransform = GetActorTransform();
	FVector SpawnLocation = GetActorLocation() + FVector(0, 0, 50.f);
	SpawnTransform.SetLocation(SpawnLocation);

	ABaseEnemyCharacter* spawned = World->SpawnActor<ABaseEnemyCharacter>(EnemyArray[PickRandomEnemy()], SpawnTransform);

	UEnemyAttributes* EnemyAttributes = spawned->GetAttributes();
	EnemyAttributes->SetMaxHealth(EnemyAttributes->GetMaxHealth() + (HealthGrow * Wave));
	EnemyAttributes->SetDamage(EnemyAttributes->GetDamage() + (DamageGrow * Wave));
	EnemyAttributes->SetSpeed(EnemyAttributes->GetSpeed() + (SpeedGrow * Wave));
}

void AEnemySpawner::SetDefaults(TArray<TSubclassOf<ABaseEnemyCharacter>> EnemiesToSpawn, float HealthGrowth, float DamageGrowth, float SpeedGrowth)
{
	EnemyArray = EnemiesToSpawn;
	HealthGrow = HealthGrowth;
	DamageGrow = DamageGrowth;
	SpeedGrow = SpeedGrowth;

}

int AEnemySpawner::PickRandomEnemy()
{
	if (EnemyArray.Num() == 0) return -1;

	return FMath::RandRange(0, EnemyArray.Num() - 1);
}


