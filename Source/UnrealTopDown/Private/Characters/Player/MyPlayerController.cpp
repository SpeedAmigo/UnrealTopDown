// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/MyPlayerController.h"


AMyPlayerController::AMyPlayerController()
{
	bEnableTouchEvents = false;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
