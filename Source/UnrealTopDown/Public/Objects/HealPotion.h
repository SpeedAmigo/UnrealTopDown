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

	virtual void PickUp_Implementation() override;
};
