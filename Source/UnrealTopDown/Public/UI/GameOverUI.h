// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API UGameOverUI : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ScoreText;

public:
	UFUNCTION()
	void SetFinalScore(int FinalScore);

};
