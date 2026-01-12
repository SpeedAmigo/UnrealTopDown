// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Enemies/EnemyDrop.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Objects/Item.h"

// Sets default values for this component's properties
UEnemyDrop::UEnemyDrop()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

TSubclassOf<AItem> UEnemyDrop::PickRandomItemToDrop()
{
	if (DropItems.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Drop Item list is empty"))
		return nullptr;
	}
	
	int32 PickedItemToDrop = FMath::RandRange(0, DropItems.Num() - 1);
	return DropItems[PickedItemToDrop];
}

bool UEnemyDrop::DecideItemDrop()
{
	float Roll = FMath::RandRange(0.f, 100.f);
	return Roll <= GlobalDropChance;
}

void UEnemyDrop::DropItem()
{
	if (!DecideItemDrop())
	{
		return;
	}
	
	TSubclassOf<AItem> Item = PickRandomItemToDrop();
	if (!Item) return;

	UWorld* World = GetWorld();
	if (!World) return;
	
	AActor* OwnerActor = GetOwner();
	
	FTransform SpawnTransform = OwnerActor ? OwnerActor->GetActorTransform() : FTransform::Identity;
	FVector SpawnLocation = SpawnTransform.GetLocation() + FVector(0, 0, 50.f);
	SpawnTransform.SetLocation(SpawnLocation);

	World->SpawnActor<AItem>(Item, SpawnTransform);
}

