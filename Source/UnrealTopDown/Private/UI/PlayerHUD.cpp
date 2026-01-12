// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void UPlayerHUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	TimePassed += InDeltaTime;
	UpdateGameTime(static_cast<float>(TimePassed));
}

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

void UPlayerHUD::UpdateGameTime(float Time)
{
    GameTimeText->SetText(FText::AsNumber(static_cast<int32>(Time)));
}

