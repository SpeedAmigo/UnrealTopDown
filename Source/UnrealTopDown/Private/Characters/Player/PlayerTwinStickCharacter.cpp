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
	DashCooldown = FMath::Max(0.f, DashCooldown - DeltaSeconds);
}

void APlayerTwinStickCharacter::Dash(const FInputActionValue& Value)
{
	if (DashCooldown <= 0.f)
	{
		Super::Dash(Value);
		DashCooldown = 2.f;
	}
}
