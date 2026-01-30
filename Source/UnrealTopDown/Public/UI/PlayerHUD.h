// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class UNREALTOPDOWN_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

private:
	int32 TotalScore;

	float InterSpeed = 10.f;

	float TimePassed;

	float OldHealth;
	float CurrentHealth;
	float MaxHealth;

	float OldEnergy;
	float CurrentEnergy;
	float MaxEnergy;

public:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnergyBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GameTimeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

public:
	void Tick(float DeltaSeconds);

	UFUNCTION()
	void UpdateHealth(float Current, float Max);

	UFUNCTION()
	void UpdateEnergy(float Current, float Max);

	UFUNCTION()
	void UpdateScore(int Points);

protected:

	void UpdateTime(float Time);

	void UpdateHealthTick(float DeltaTime);

	void UpdateEnergyTick(float DeltaTime);
};
