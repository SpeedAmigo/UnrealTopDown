// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Variant_TwinStick/TwinStickPlayerController.h"
#include "MyPlayerController.generated.h"

class AEnemySpawnerManager;
class UPlayerHUD;
class APlayerTwinStickCharacter;
class UUserWidget;
class UPlayerAttributesComponent;

UCLASS()
class UNREALTOPDOWN_API AMyPlayerController : public ATwinStickPlayerController
{
	GENERATED_BODY()

protected:

	UPlayerAttributesComponent* PlayerAttributesComponent;
	APlayerTwinStickCharacter* PlayerCharacter;
	AEnemySpawnerManager* SpawnerManager;

private:
	UPROPERTY(EditAnywhere, Category="UI")
	UPlayerHUD* PlayerHUD;


public:
	AMyPlayerController();

	void AssignSpawnManager(AEnemySpawnerManager* NewSpawnManager);

	virtual void OnPossess(APawn* InPawn) override;

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
};
