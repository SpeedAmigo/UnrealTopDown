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

protected:

	UPlayerAttributesComponent* PlayerAttributesComponent;
	APlayerTwinStickCharacter* PlayerCharacter;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	UAnimMontage* DeathMontage;

private:
	UPROPERTY(EditAnywhere, Category="UI")
	UPlayerHUD* PlayerHUD;

	UPROPERTY(EditAnywhere, Category="UI")
	UGameOverUI* GameOverUI;

	UPROPERTY(EditDefaultsOnly, Category = "SFX")
	USoundBase* DeathCue;

public:
	UPlayerHUD* GetPlayerHUD() { return PlayerHUD; }

	UFUNCTION(BlueprintCallable, Category="Death")
	void PostDeathAnim();

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
