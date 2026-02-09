// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyAttributes.generated.h"


class ABaseEnemyCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTOPDOWN_API UEnemyAttributes : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyAttributes();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Damage;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float Points;

private:

	ABaseEnemyCharacter* Owner;

public:	
	int GetPoints() const { return Points; }
	
	float GetHealth() const { return CurrentHealth; }
	float GetMaxHealth() const { return MaxHealth; }
	float GetDamage() const { return Damage; }
	float GetSpeed();

	void SetHealth(float NewCurrentHealth);
	void SetDamage(float NewDamage);
	void SetSpeed(float NewSpeed);

	void SetMaxHealth(float NewMaxHealth);
};
