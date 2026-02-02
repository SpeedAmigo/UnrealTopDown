// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/BasePot.h"

#include "Characters/Enemies/EnemyDrop.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

ABasePot::ABasePot()
{
	DropComponent = CreateDefaultSubobject<UEnemyDrop>(TEXT("DropComp"));
	GeometryCollection->SetEnableDamageFromCollision(false);
}

void ABasePot::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->IsA(APlayerTwinStickCharacter::StaticClass()))
	{
		GeometryCollection->SetEnableDamageFromCollision(true);
	}
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
