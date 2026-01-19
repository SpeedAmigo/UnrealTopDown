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

void APlayerTwinStickCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other,
	class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->Implements<UInteractable>())
	{
		IInteractable::Execute_PickUp(Other);
	}
}
