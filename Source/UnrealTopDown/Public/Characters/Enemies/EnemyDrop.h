// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyDrop.generated.h"

class AItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTOPDOWN_API UEnemyDrop : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drop")
	TArray<TSubclassOf<AItem>> DropItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drop",
		meta = (ClampMin = "0.0", ClampMax = "100", UIMin = "0.0", UIMax = "100"))
	int GlobalDropChance;

public:
	// Sets default values for this component's properties
	UEnemyDrop();
	
	void DropItem();
	
private:
	TSubclassOf<AItem> PickRandomItemToDrop();
	//bool DecideItemDrop();
};
