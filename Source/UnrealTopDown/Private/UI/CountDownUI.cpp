// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CountDownUI.h"

#include "Components/TextBlock.h"

void UCountDownUI::UpdateCountdownText(float Time)
{
	int Seconds = FMath::FloorToInt(Time);
	WaveCountdownText->SetText(FText::FromString(FString::Printf(TEXT("Next Wave In: %d..."), Seconds)));
}
