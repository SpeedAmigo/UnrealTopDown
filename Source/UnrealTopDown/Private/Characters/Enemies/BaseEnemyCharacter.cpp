// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/BaseEnemyCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/MeshComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
}

