// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/MyPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Characters/Player/PlayerAttributesComponent.h"
#include "Characters/Player/PlayerTwinStickCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GameOverUI.h"
#include "UI/PlayerHUD.h"



AMyPlayerController::AMyPlayerController()
{
	bEnableTouchEvents = false;
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (PlayerHUD)
	{
		PlayerHUD->Tick(DeltaSeconds);
	}
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
		PlayerAttributesComponent->OnEnergyChanged.AddDynamic(PlayerHUD, &UPlayerHUD::UpdateEnergy);
		PlayerAttributesComponent->OnDeath.AddDynamic(this, &AMyPlayerController::Death);
	}
}

void AMyPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (PlayerCharacter && PlayerAttributesComponent)
	{
		PlayerAttributesComponent->OnHealthChanged.RemoveDynamic(PlayerHUD, &UPlayerHUD::UpdateHealth);
		PlayerAttributesComponent->OnEnergyChanged.RemoveDynamic(PlayerHUD, &UPlayerHUD::UpdateEnergy);
		PlayerAttributesComponent->OnDeath.RemoveDynamic(this, &AMyPlayerController::Death);
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (PlayerHUD)
	{
		PlayerHUD->CastCanvasSlots();
	}
}


void AMyPlayerController::Death()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->DisableInput(this);
		PlayerCharacter->PlayAnimMontage(DeathMontage);
	}
	UGameplayStatics::PlaySound2D(GetWorld(), DeathCue);
	
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AMyPlayerController::PostDeathAnim()
{
	if (GameOverUI)
	{
		GameOverUI->AddToViewport();
		GameOverUI->SetFinalScore(PlayerHUD->GetFinalScore());
	}
}


