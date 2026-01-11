// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/MyPlayerController.h"

#include "Characters/Player/PlayerAttributesComponent.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "UI/PlayerHUD.h"


AMyPlayerController::AMyPlayerController()
{
	bEnableTouchEvents = false;
}

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (PlayerHUD)
	{
		PlayerHUD->AddToViewport();
	}
	PlayerCharacter = Cast<APlayerTwinStickCharacter>(InPawn);
	if (PlayerCharacter)
	{
		PlayerAttributesComponent = PlayerCharacter->GetPlayerAttributesComponent();

		PlayerAttributesComponent->OnHealthChanged.AddDynamic(PlayerHUD, &UPlayerHUD::UpdateHealth);
		PlayerAttributesComponent->OnStaminaChanged.AddDynamic(PlayerHUD, &UPlayerHUD::UpdateStamina);
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
