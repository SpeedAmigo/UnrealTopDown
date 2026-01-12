// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Combat.h"
#include "BaseEnemyCharacter.generated.h"

class UEnemyDrop;
class UEnemyAttributes;
enum class PawnState : uint8;
class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class UNREALTOPDOWN_API ABaseEnemyCharacter : public ACharacter, public ICombat
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "State")
	PawnState PawnState;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
	UEnemyAttributes* Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EnemyDrop")
	UEnemyDrop* EnemyDrop;

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetDamage_Implementation(float amount);
	
};
