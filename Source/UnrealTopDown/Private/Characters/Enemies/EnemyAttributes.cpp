// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/EnemyAttributes.h"

// Sets default values for this component's properties
UEnemyAttributes::UEnemyAttributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
}


// Called when the game starts
void UEnemyAttributes::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
}


// Called every frame
void UEnemyAttributes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UEnemyAttributes::GetHealth() const { return CurrentHealth; }

float UEnemyAttributes::GetMaxHealth() const{ return MaxHealth; }

float UEnemyAttributes::GetStamina() const { return CurrentStamina; }

float UEnemyAttributes::GetMaxStamina() const{ return MaxStamina; }

float UEnemyAttributes::GetDamage() const{ return Damage; }

void UEnemyAttributes::SetHealth(float NewCurrentHealth)
{
	CurrentHealth = NewCurrentHealth;
}

void UEnemyAttributes::SetStamina(float NewCurrentStamina)
{
	CurrentStamina = NewCurrentStamina;
}

void UEnemyAttributes::SetDamage(float NewDamage)
{
	Damage = NewDamage;
}

void UEnemyAttributes::SetMaxHealth(float NewMaxHealth)
{
	MaxHealth = NewMaxHealth;
}

void UEnemyAttributes::SetMaxStamina(float NewMaxStamina)
{
	MaxStamina = NewMaxStamina;
}

