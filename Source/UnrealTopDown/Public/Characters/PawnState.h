// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class PawnState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Moving UMETA(DisplayName = "Moving"),
	InCombat UMETA(DisplayName = "InCombat"),
	Dead UMETA(DisplayName = "Dead"),
};
