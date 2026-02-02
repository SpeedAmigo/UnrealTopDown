#include "Characters/Player/PlayerTwinStickCharacter.h"

#include "TwinStickProjectile.h"
#include "Characters/Player/PlayerAttributesComponent.h"
#include "Engine/World.h"
#include "Interfaces/Interactable.h"
#include "Kismet/GameplayStatics.h"
#include "Management/ArrowType.h"

APlayerTwinStickCharacter::APlayerTwinStickCharacter()
{
	bUsingMouse = true;

	PlayerAttributesComponent = CreateDefaultSubobject<UPlayerAttributesComponent>(TEXT("PlayerAttributesComponent"));
}

void APlayerTwinStickCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ArrowType = ArrowType::SingleShot;
	//UE_LOG(LogTemp, Warning, TEXT("Arrow Type: %i"), ArrowType);
}

void APlayerTwinStickCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DashTimer = FMath::Max(0.f, DashTimer - DeltaSeconds);
	if (ArrowType != ArrowType::SingleShot)
	{
		SpecialArrowTimer = FMath::Max(0.f, SpecialArrowTimer - DeltaSeconds);
		if (SpecialArrowTimer <= 0.f)
		{
			ArrowType = ArrowType::SingleShot;
		}
	}

}

void APlayerTwinStickCharacter::Dash(const FInputActionValue& Value)
{
	if (DashTimer <= 0.f && PlayerAttributesComponent->GetEnergy() >= DashCost)
	{
		Super::Dash(Value);
		DashTimer = DashCooldown;
		PlayerAttributesComponent->SubtractEnergy(DashCost);

		if (DashSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), DashSound, GetActorLocation());
		}

		OnDash.Broadcast();
	}
}

void APlayerTwinStickCharacter::Shoot(const FInputActionValue& Value)
{
	if (PlayerAttributesComponent->GetEnergy() < ShootCost) return;

	switch (ArrowType)
	{
		case ArrowType::SingleShot:
			DoShoot(ArrowSpawnGroup[0]);
			PlayerAttributesComponent->SubtractEnergy(ShootCost);
		break;
		case ArrowType::DoubleShot:
			DoShoot(ArrowSpawnGroup[1]);
			PlayerAttributesComponent->SubtractEnergy(ShootCost);
		break;
		case ArrowType::TripleShot:
			DoShoot(ArrowSpawnGroup[2]);
			PlayerAttributesComponent->SubtractEnergy(ShootCost);
		break;
	}
}
void APlayerTwinStickCharacter::DoShoot(FArrowSpawnGroup ArrowData)
{
	// get the actor transform
	FTransform ProjectileTransform = GetActorTransform();
	
	for (int i = 0; i < ArrowData.SpawnedActors.Num(); i++)
	{
		FArrowTransformStruct ArrowTransform = ArrowData.SpawnedActors[i];
		
		// Location offset
		FVector ProjectileLocation =
			ProjectileTransform.GetLocation() +
			ProjectileTransform.GetRotation().RotateVector(ArrowTransform.PositionOffset);
		
		// Rotation offset
		FQuat ProjectileRotation =
			ProjectileTransform.GetRotation() *
			ArrowTransform.LocalRotationOffset.Quaternion();

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(ProjectileLocation);
		SpawnTransform.SetRotation(ProjectileRotation);

		GetWorld()->SpawnActor<ATwinStickProjectile>(ProjectileClass, SpawnTransform);

		if (ArrowRelease)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ArrowRelease, ProjectileLocation);
		}
	}
}

void APlayerTwinStickCharacter::GetDamage_Implementation(float amount)
{
	PlayerAttributesComponent->TakeDamage(amount);
}

void APlayerTwinStickCharacter::ResetArrowTimer()
{
	SpecialArrowTimer = SpecialArrowTotalTime;
}


void APlayerTwinStickCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->Implements<UInteractable>())
	{
		IInteractable::Execute_PickUp(OtherActor, this);
		if (PickupSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		}
	}
}
