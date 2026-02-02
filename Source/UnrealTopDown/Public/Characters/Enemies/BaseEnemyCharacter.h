// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Combat.h"
#include "BaseEnemyCharacter.generated.h"

class UPlayerHUD;
class AMyPlayerController;
class UNiagaraSystem;
class APlayerTwinStickCharacter;
class UEnemyDrop;
class UEnemyAttributes;
enum class PawnState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDiedSignature, int, Points);

UCLASS()
class UNREALTOPDOWN_API ABaseEnemyCharacter : public ACharacter, public ICombat
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnEnemyDiedSignature OnEnemyDied;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "State")
	PawnState PawnState;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
	UEnemyAttributes* Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EnemyDrop")
	UEnemyDrop* EnemyDrop;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* SpawnAndDeathVFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
	USoundBase* DieSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
	USoundBase* AttackSound;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	float AttackCooldown = 2.f;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	UAnimMontage* AttackMontage;

private:

	APlayerTwinStickCharacter* PlayerCharacter;
	AMyPlayerController* PlayerController;
	UPlayerHUD* PlayerHUD;

	float AttackTimer;

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

	void DealDamage(AActor* OtherActor);

	UEnemyAttributes* GetAttributes() const { return Attributes; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetDamage_Implementation(float amount);
	
};
