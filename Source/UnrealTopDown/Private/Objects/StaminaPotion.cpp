// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/StaminaPotion.h"

#include "Characters/Player/PlayerAttributesComponent.h"

void AStaminaPotion::PickUp_Implementation(AActor* Actor)
{
	if (UPlayerAttributesComponent* PlayerAttr = Actor->FindComponentByClass<UPlayerAttributesComponent>())
	{
		if (IncreaseMaxStamina)
		{
			PlayerAttr->AddMaxEnergy(MaxStaminaIncreasePoints);
		}

		PlayerAttr->AddEnergy(EnergyPoints);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor has no PlayerAttributesComponent"));
	}
	
	Super::PickUp_Implementation(Actor);
}
