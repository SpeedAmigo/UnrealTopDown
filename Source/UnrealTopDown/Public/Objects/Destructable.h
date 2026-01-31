// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Physics/Experimental/ChaosEventType.h"
#include "Destructable.generated.h"

class UGeometryCollectionComponent;
class USceneComponent;

UCLASS()
class UNREALTOPDOWN_API ADestructable : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* Root;
	
	UPROPERTY(visibleAnywhere, Category = "Components")
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* BreakSound;
	
	UPROPERTY(VisibleAnywhere, Category = "Break")
	bool HasBeenFragmented;

public:
	
	ADestructable();

protected:
	
	virtual void BeginPlay() override;
	virtual void HandleFragmentation();

private:

	UFUNCTION()
	void OnFragmentation(const FChaosBreakEvent& BreakEvent);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
