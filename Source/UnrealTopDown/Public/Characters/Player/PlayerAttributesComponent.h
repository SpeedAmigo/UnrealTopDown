// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerAttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStaminaChangedSignature, float, CurrentStamina, float, MaxStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTOPDOWN_API UPlayerAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnHealthChangedSignature OnHealthChanged;
	UPROPERTY()
	FOnStaminaChangedSignature OnStaminaChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float MaxEnergy = 100.f;

	float Health;
	float Energy;

public:	
	// Sets default values for this component's properties
	UPlayerAttributesComponent();
	void TakeDamage(float DamageAmount);

protected:
	virtual void BeginPlay() override;

};
