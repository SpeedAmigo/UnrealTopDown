// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerHUD::Tick(float DeltaSeconds)
{
	TimePassed += DeltaSeconds;
	UpdateTime(TimePassed);

	if (OldHealth != CurrentHealth)
		UpdateHealthTick(DeltaSeconds);
	if (OldEnergy != CurrentEnergy)
		UpdateEnergyTick(DeltaSeconds);
}

void UPlayerHUD::UpdateHealth(float Current, float Max)
{
	OldHealth = CurrentHealth;
	CurrentHealth = Current;
	MaxHealth = Max;
}

void UPlayerHUD::UpdateEnergy(float Current, float Max)
{
	OldHealth = CurrentHealth;
	CurrentEnergy = Current;
	MaxEnergy = Max;
}

void UPlayerHUD::UpdateScore(int Points)
{
	TotalScore += Points;
	ScoreText->SetText(FText::FromString(FString::Printf(TEXT("%d | Score"), TotalScore)));
}

void UPlayerHUD::UpdateTime(float Time)
{
	if (Time <= 60.f)
	{
		int32 Seconds = FMath::FloorToInt(FMath::Fmod(Time, 60.f));
		GameTimeText->SetText(FText::FromString(FString::Printf(TEXT("%d s | Time"), Seconds)));
	}
	else
	{
		int32 Minutes = FMath::FloorToInt(Time / 60.f);
		int32 Seconds = FMath::FloorToInt(FMath::Fmod(Time, 60.f));
		GameTimeText->SetText(FText::FromString(FString::Printf(TEXT("%d m %d s | Time"), Minutes, Seconds)));
	}
}

void UPlayerHUD::UpdateHealthTick(float DeltaTime)
{
	OldHealth = FMath::FInterpTo(OldHealth, CurrentHealth, DeltaTime, InterSpeed);
	HealthBar->SetPercent(OldHealth / MaxHealth);
}

void UPlayerHUD::UpdateEnergyTick(float DeltaTime)
{
	OldEnergy = FMath::FInterpTo(OldEnergy, CurrentEnergy, DeltaTime, InterSpeed);
	EnergyBar->SetPercent(OldEnergy / MaxEnergy);
}
