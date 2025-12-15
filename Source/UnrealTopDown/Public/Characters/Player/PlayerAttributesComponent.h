// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerAttributesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTOPDOWN_API UPlayerAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	float MaxHealth = 100.f;
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	float MaxEnergy = 100.f;

	float Health;
	float Energy;

public:	
	// Sets default values for this component's properties
	UPlayerAttributesComponent();

protected:
	virtual void BeginPlay() override;
};
