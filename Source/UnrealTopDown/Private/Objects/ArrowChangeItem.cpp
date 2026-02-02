// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/ArrowChangeItem.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"

void AArrowChangeItem::PickUp_Implementation(AActor* Actor)
{
	if (APlayerTwinStickCharacter* Player = Cast<APlayerTwinStickCharacter>(Actor))
	{
		if (Player->ArrowType >= Type)
			Player->ResetArrowTimer();
		else
		{
			Player->ArrowType = Type;
			Player->ResetArrowTimer();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor has no PlayerAttributesComponent"));
	}
 	
	Super::PickUp_Implementation(Actor);
}
