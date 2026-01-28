// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/BaseEnemyCharacter.h"
#include "Characters/Enemies/BaseEnemyCharacter.h"

#include "Characters/PawnState.h"
#include "Characters/Enemies/EnemyAIController.h"
#include "Characters/Enemies/EnemyAttributes.h"
#include "Characters/Enemies/EnemyDrop.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Objects/EnemySpawner.h"
#include "NiagaraComponent.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	Attributes = CreateDefaultSubobject<UEnemyAttributes>(TEXT("Attributes"));
	EnemyDrop = CreateDefaultSubobject<UEnemyDrop>(TEXT("EnemyDrop"));

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraVFX"));
	NiagaraComp->SetupAttachment(RootComponent);

	NiagaraComp->SetAutoActivate(true);
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PawnState = PawnState::Moving;

	PlayerCharacter = Cast<APlayerTwinStickCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ABaseEnemyCharacter::GetDamage_Implementation(float amount)
{
	float Health = Attributes->GetHealth();
	Health -= amount;
	
	if (Health <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Died!"))
		if (EnemyDrop)
		{
			EnemyDrop->DropItem();
		}
		Spawner->SpawnedEnemyDies();

		if (NiagaraComp)
		{
			NiagaraComp->Activate(true);
			NiagaraComp->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
			NiagaraComp->SetAutoDestroy(true);
		}

		if (DieSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DieSound, GetActorLocation());
		}
		
		Destroy();
	}
	else
	{
		Attributes->SetHealth(Health);
	}
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AttackTimer -= DeltaTime;

	if (AttackTimer > 0.f || !PlayerCharacter) return;
	if ((PlayerCharacter->GetActorLocation() - GetActorLocation()).Size() < 100.0f)
	{
		if (AttackMontage)
		{
			PlayAnimMontage(AttackMontage);
		}
		DealDamage(PlayerCharacter);
		AttackTimer = AttackCooldown;
		UE_LOG(LogTemp, Display, TEXT("Enemy attacked player"));
	}
}

void ABaseEnemyCharacter::DealDamage(AActor* OtherActor)
{
	if (OtherActor->Implements<UCombat>())
	{
		Execute_GetDamage(OtherActor, Attributes->Damage);
	}
}

