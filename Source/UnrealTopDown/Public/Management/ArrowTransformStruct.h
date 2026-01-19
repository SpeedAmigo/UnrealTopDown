// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArrowTransformStruct.generated.h"

USTRUCT(BlueprintType)
struct FArrowTransformStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PositionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator LocalRotationOffset;
};
