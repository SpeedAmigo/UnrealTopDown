// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerAttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnergyChangedSignature, float, CurrentStamina, float, MaxStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, CurrentHealth, float, MaxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTOPDOWN_API UPlayerAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY()
	FOnEnergyChangedSignature OnEnergyChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	float MaxEnergy = 100.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Attributes")
	float EnergyRegen = 1.f;

	float Health;
	float Energy;

public:	
	// Sets default values for this component's properties
	UPlayerAttributesComponent();

	void TakeDamage(float DamageAmount);
	void Heal(float HealAmount);
	void SubtractEnergy(float EnergyAmount);
	void AddEnergy(float EnergyAmount);

	float GetEnergy() { return Energy; }
	float GetHealth() { return Health; }

protected:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
