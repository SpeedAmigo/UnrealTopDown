#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Characters/Player/PlayerAttributesComponent.h"

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
