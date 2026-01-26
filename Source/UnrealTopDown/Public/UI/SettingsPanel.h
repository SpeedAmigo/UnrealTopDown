// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsPanel.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTOPDOWN_API USettingsPanel : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;
};
