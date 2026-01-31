// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/Destructable.h"
#include "BasePot.generated.h"

class UEnemyDrop;
/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API ABasePot : public ADestructable
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category = "DropComp")
	UEnemyDrop* DropComponent;

public:
	ABasePot();

protected:

	virtual void HandleFragmentation() override;
};
