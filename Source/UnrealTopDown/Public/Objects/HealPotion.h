// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/Item.h"
#include "HealPotion.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API AHealPotion : public AItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float HealPoints;

protected:

	virtual void PickUp_Implementation(AActor* Actor) override;
};
