// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Combat.h"
#include "BaseEnemyCharacter.generated.h"

class UNiagaraComponent;
class APlayerTwinStickCharacter;
class AEnemySpawner;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VFX")
	UNiagaraComponent* NiagaraComp;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	float AttackCooldown = 2.f;

	AEnemySpawner* Spawner;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	UAnimMontage* AttackMontage;

private:
	APlayerTwinStickCharacter* PlayerCharacter;

	float AttackTimer;

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

	void DealDamage(AActor* OtherActor);

	void AssignSpawner(AEnemySpawner* NewSpawner) { Spawner = NewSpawner; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetDamage_Implementation(float amount);
	
};
