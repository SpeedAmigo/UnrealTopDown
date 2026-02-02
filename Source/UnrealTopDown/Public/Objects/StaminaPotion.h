// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/Item.h"
#include "StaminaPotion.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API AStaminaPotion : public AItem
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool IncreaseMaxStamina = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MaxStaminaIncreasePoints;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float EnergyPoints;

protected:
	virtual void PickUp_Implementation(AActor* Actor) override;
};
