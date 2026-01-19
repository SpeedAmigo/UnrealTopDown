// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/StaminaPotion.h"

void AStaminaPotion::PickUp_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Stamina Potion Picked Up!"));
	
	Super::PickUp_Implementation();
}
