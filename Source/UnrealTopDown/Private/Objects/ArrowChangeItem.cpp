// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/ArrowChangeItem.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"

void AArrowChangeItem::PickUp_Implementation(AActor* Actor)
{
	if (APlayerTwinStickCharacter* Player = Cast<APlayerTwinStickCharacter>(Actor))
	{
		Player->ArrowType = Type;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor has no PlayerAttributesComponent"));
	}
 	
	Super::PickUp_Implementation(Actor);
}
