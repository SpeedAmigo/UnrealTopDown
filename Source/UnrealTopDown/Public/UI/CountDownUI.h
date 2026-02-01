// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CountDownUI.generated.h"

UCLASS()
class UNREALTOPDOWN_API UCountDownUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* WaveCountdownText;

public:
	void UpdateCountdownText(float Time);
};
