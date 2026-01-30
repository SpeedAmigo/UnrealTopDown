// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/BaseProjectile.h"

#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Components/SphereComponent.h"
#include "Interfaces/Combat.h"
#include "Kismet/GameplayStatics.h"

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseProjectile::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->Implements<UCombat>() && !Cast<APlayerTwinStickCharacter>(Other))
	{
		ICombat::Execute_GetDamage(Other, Damage);
		Destroy();
	}
}
