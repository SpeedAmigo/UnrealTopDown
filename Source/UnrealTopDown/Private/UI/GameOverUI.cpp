// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameOverUI.h"
#include "Components/TextBlock.h"

void UGameOverUI::SetFinalScore(int FinalScore)
{
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), FinalScore)));
	}
}
