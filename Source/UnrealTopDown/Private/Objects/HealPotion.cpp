// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/HealPotion.h"

void AHealPotion::PickUp_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Heal Potion Picked Up!"))
	
	Super::PickUp_Implementation();
}
