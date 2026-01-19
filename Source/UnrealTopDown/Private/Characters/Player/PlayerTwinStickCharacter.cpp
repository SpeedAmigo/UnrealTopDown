#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Characters/Player/PlayerAttributesComponent.h"
#include "Interfaces/Combat.h"
#include "Interfaces/Interactable.h"

APlayerTwinStickCharacter::APlayerTwinStickCharacter()
{
	bUsingMouse = true;

	PlayerAttributesComponent = CreateDefaultSubobject<UPlayerAttributesComponent>(TEXT("PlayerAttributesComponent"));
}

void APlayerTwinStickCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerTwinStickCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DashTimer = FMath::Max(0.f, DashTimer - DeltaSeconds);
}

void APlayerTwinStickCharacter::Dash(const FInputActionValue& Value)
{
	if (DashTimer <= 0.f && PlayerAttributesComponent->GetEnergy() >= DashCost)
	{
		Super::Dash(Value);
		DashTimer = DashCooldown;
		PlayerAttributesComponent->SubtractEnergy(DashCost);
	}
}

void APlayerTwinStickCharacter::Shoot(const FInputActionValue& Value)
{
	if (PlayerAttributesComponent->GetEnergy() >= ShootCost)
	{
		Super::Shoot(Value);
		PlayerAttributesComponent->SubtractEnergy(ShootCost);
	}
}

void APlayerTwinStickCharacter::AoEAttack(const FInputActionValue& Value)
{
	if (PlayerAttributesComponent->GetEnergy() >= AoECost)
	{
		Super::AoEAttack(Value);
		PlayerAttributesComponent->SubtractEnergy(AoECost);
	}
}

void APlayerTwinStickCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other,
	class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->Implements<UInteractable>())
	{
		IInteractable::Execute_PickUp(Other);
	}
}
