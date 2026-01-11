// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"

#include "Components/ProgressBar.h"


void UPlayerHUD::UpdateHealth(float Current, float Max)
{
	HealthBar->SetPercent(Current / Max);
}

void UPlayerHUD::UpdateStamina(float Current, float Max)
{
	EnergyBar->SetPercent(Current / Max);
}