// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/HealPotion.h"

#include "Characters/Player/PlayerAttributesComponent.h"

void AHealPotion::PickUp_Implementation(AActor* Actor)
{
	if (UPlayerAttributesComponent* PlayerAttr = Actor->FindComponentByClass<UPlayerAttributesComponent>())
	{
		PlayerAttr->Heal(HealPoints);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor has no PlayerAttributesComponent"));
	}
 	
	Super::PickUp_Implementation(Actor);
}
