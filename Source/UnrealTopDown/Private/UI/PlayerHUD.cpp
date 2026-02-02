// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"

#include "Components/CanvasPanelSlot.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerHUD::Tick(float DeltaSeconds)
{
	TimePassed += DeltaSeconds;
	UpdateTime(TimePassed);

	UpdateHealthTick(DeltaSeconds);
	UpdateEnergyTick(DeltaSeconds);
}

void UPlayerHUD::CastCanvasSlots()
{

	HealthBarSlot = Cast<UCanvasPanelSlot>(HealthBar->Slot);
	EnergyBarSlot = Cast<UCanvasPanelSlot>(EnergyBar->Slot);
}

void UPlayerHUD::UpdateHealth(float Current, float Max)
{
	//OldHealth = CurrentHealth;
	MaxHealth = Max;
	CurrentHealth = Current;
	HealthText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), FMath::FloorToInt(CurrentHealth), FMath::FloorToInt(MaxHealth))));
}

void UPlayerHUD::UpdateHealthTick(float DeltaTime)
{
	OldMaxHealth = FMath::FInterpTo(OldMaxHealth, MaxHealth, DeltaTime, InterSpeed);
	HealthBarSlot->SetSize(FVector2D(FMath::Clamp(OldMaxHealth * 4.f, 0.f, 1200.f), 40.f));

	OldHealth = FMath::FInterpTo(OldHealth, CurrentHealth, DeltaTime, InterSpeed);
	HealthBar->SetPercent(OldHealth / MaxHealth);
}

void UPlayerHUD::UpdateEnergy(float Current, float Max)
{
	//OldEnergy = CurrentEnergy;
	MaxEnergy = Max;
	CurrentEnergy = Current;
	EnergyText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), FMath::FloorToInt(CurrentEnergy), FMath::FloorToInt(MaxEnergy))));
}

void UPlayerHUD::UpdateEnergyTick(float DeltaTime)
{
	OldMaxEnergy = FMath::FInterpTo(OldMaxEnergy, MaxEnergy, DeltaTime, InterSpeed);
	EnergyBarSlot->SetSize(FVector2D(FMath::Clamp(OldMaxEnergy * 4.f, 0.f, 1200.f), 40.f));

	OldEnergy = FMath::FInterpTo(OldEnergy, CurrentEnergy, DeltaTime, InterSpeed);
	EnergyBar->SetPercent(OldEnergy / MaxEnergy);
}

void UPlayerHUD::UpdateScore(int Points)
{
	TotalScore += Points;
	ScoreText->SetText(FText::FromString(FString::Printf(TEXT("%d | Score"), TotalScore)));
}

void UPlayerHUD::UpdateWave(int Wave)
{
	WaveText->SetText(FText::FromString(FString::Printf(TEXT("%d | Wave"), Wave)));
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
