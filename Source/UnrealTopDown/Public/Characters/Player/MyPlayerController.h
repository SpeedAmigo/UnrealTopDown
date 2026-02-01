// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Variant_TwinStick/TwinStickPlayerController.h"
#include "MyPlayerController.generated.h"

class UGameOverUI;
class AEnemySpawnerManager;
class UPlayerHUD;
class APlayerTwinStickCharacter;
class UPlayerAttributesComponent;


UCLASS()
class UNREALTOPDOWN_API AMyPlayerController : public ATwinStickPlayerController
{
	GENERATED_BODY()

public:

protected:

	UPlayerAttributesComponent* PlayerAttributesComponent;
	APlayerTwinStickCharacter* PlayerCharacter;
	AEnemySpawnerManager* SpawnerManager;

private:
	UPROPERTY(EditAnywhere, Category="UI")
	UPlayerHUD* PlayerHUD;

	UPROPERTY(EditAnywhere, Category="UI")
	UGameOverUI* GameOverUI;

public:
	UPlayerHUD* GetPlayerHUD() { return PlayerHUD; }

protected:
	AMyPlayerController();

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Death();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
