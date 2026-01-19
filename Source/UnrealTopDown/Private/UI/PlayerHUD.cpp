// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerHUD::UpdateHealth(float Current, float Max)
{
	HealthBar->SetPercent(Current / Max);
}

void UPlayerHUD::UpdateStamina(float Current, float Max)
{
	EnergyBar->SetPercent(Current / Max);
}

void UPlayerHUD::UpdateScore(int32 Score)
{
    ScoreText->SetText(FText::AsNumber(Score));
}

