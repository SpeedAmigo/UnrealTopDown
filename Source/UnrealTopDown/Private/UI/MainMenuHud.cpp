// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuHud.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuHud::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	NewGameButton->OnPressed.AddDynamic(this, &UMainMenuHud::OnNewGameButtonPressed);

	QuitButton->OnPressed.AddDynamic(this, &UMainMenuHud::OnExitGamePressed);
}

void UMainMenuHud::OnNewGameButtonPressed()
{
	UGameplayStatics::OpenLevel(this, FName("Lvl_TopDown"));
}

void UMainMenuHud::OnExitGamePressed()
{
	UKismetSystemLibrary::QuitGame(GWorld, nullptr, EQuitPreference::Quit, false);
}
