// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemyCharacter.generated.h"

enum class PawnState : uint8;
class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class UNREALTOPDOWN_API ABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "State")
	PawnState PawnState;

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
