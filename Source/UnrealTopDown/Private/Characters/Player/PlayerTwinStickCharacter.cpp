#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Characters/Player/PlayerAttributesComponent.h"

APlayerTwinStickCharacter::APlayerTwinStickCharacter()
{
	PlayerAttributesComponent = CreateDefaultSubobject<UPlayerAttributesComponent>(TEXT("PlayerAttributesComponent"));
}

void APlayerTwinStickCharacter::BeginPlay()
{
	Super::BeginPlay();
}
