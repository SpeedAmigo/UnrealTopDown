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

	if (OnStaminaChanged.IsBound())
	{
		OnStaminaChanged.Broadcast(Energy, MaxEnergy);
	}
	if (OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
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

