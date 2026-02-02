// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Destructable.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADestructable::ADestructable()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	GeometryCollection->SetupAttachment(RootComponent);

	GeometryCollection->SetNotifyBreaks(true);
	
}

// Called when the game starts or when spawned
void ADestructable::BeginPlay()
{
	Super::BeginPlay();

	if (GeometryCollection)
	{
		GeometryCollection->OnChaosBreakEvent.AddDynamic(this, &ADestructable::OnFragmentation);
	}
}

void ADestructable::HandleFragmentation() {}

void ADestructable::OnFragmentation(const FChaosBreakEvent& BreakEvent)
{
	if (!HasBeenFragmented)
	{
		HandleFragmentation();
		
		if (BreakSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				this,
				BreakSound,
				GetActorLocation());
		}
		
		HasBeenFragmented = true;
	}
}

// Called every frame
void ADestructable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

