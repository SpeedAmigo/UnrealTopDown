// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/PlayerAttributesComponent.h"

// Sets default values for this component's properties
UPlayerAttributesComponent::UPlayerAttributesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerAttributesComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Energy = MaxEnergy;

	if (OnEnergyChanged.IsBound())
	{
		OnEnergyChanged.Broadcast(Energy, MaxEnergy);
	}
	if (OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
}

void UPlayerAttributesComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Energy >= MaxEnergy) return;
	AddEnergy(EnergyRegen * DeltaTime);
}

void UPlayerAttributesComponent::TakeDamage(float DamageAmount)
{
	if (DamageAmount <= 0.0f) return;

	float OldHealth = Health;
	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);

	//UE_LOG(LogTemp, Warning, TEXT("%s took %.2f damage. Health: %.2f / %.2f"), 
	//	*GetOwner()->GetName(), DamageAmount, Health, MaxHealth);

	// Broadcast death if health reached zero
	if (OldHealth > 0.0f && Health <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has died!"), *GetOwner()->GetName());
		/*if (OnDeath.IsBound())
		{
			OnDeath.Broadcast();
		}*/
	}
	/*if (OnTakeDamage.IsBound() && Health > 0.f)
	{
		OnTakeDamage.Broadcast();
	}*/
	if (OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
}

void UPlayerAttributesComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.0f) return;

	Health = FMath::Clamp(Health + HealAmount, 0.0f, MaxHealth);

	if (OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
}

void UPlayerAttributesComponent::SubtractEnergy(float EnergyAmount)
{
	if (EnergyAmount <= 0.0f) return;

	Energy = FMath::Clamp(Energy - EnergyAmount, 0.0f, MaxEnergy);
	if (OnEnergyChanged.IsBound())
	{
		OnEnergyChanged.Broadcast(Energy, MaxEnergy);
	}
}

void UPlayerAttributesComponent::AddEnergy(float EnergyAmount)
{
	if (EnergyAmount <= 0) return;

	Energy = FMath::Clamp(Energy + EnergyAmount, 0.0f, MaxEnergy);
	if (OnEnergyChanged.IsBound())
	{
		OnEnergyChanged.Broadcast(Energy, MaxEnergy);
	}
}

