// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/BasePot.h"

#include "Characters/Enemies/EnemyDrop.h"

ABasePot::ABasePot()
{
	DropComponent = CreateDefaultSubobject<UEnemyDrop>(TEXT("DropComp"));
}

void ABasePot::HandleFragmentation()
{
	if (DropComponent)
	{
		DropComponent->DropItem();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Drop Item Fail"));
	}
}
