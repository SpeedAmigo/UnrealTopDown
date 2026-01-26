// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/Item.h"
#include "ArrowChangeItem.generated.h"

enum class ArrowType : uint8;
/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API AArrowChangeItem : public AItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow")
	ArrowType Type;

protected:
	virtual void PickUp_Implementation(AActor* Actor) override;
};
