// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArrowTransformStruct.h"
#include "ArrowSpawnGroup.generated.h"

USTRUCT(BlueprintType)
struct FArrowSpawnGroup
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArrowSpawnStruct")
	TArray<FArrowTransformStruct> SpawnedActors;
};
