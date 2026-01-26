// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuHud.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API UMainMenuHud : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* NewGameButton;
	UPROPERTY(meta = (BindWidget))
	UButton* OptionsButton;
	UPROPERTY(meta = (BindWidget))
	UButton* CreditsButton;
	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

protected:
	UFUNCTION()
	void OnNewGameButtonPressed();
	UFUNCTION()
	void OnExitGamePressed();
	virtual void NativeOnInitialized() override;
};
