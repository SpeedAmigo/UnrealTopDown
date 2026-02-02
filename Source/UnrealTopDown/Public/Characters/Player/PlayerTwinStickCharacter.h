#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Combat.h"
#include "Management/ArrowSpawnGroup.h"
#include "Variant_TwinStick/TwinStickCharacter.h"
#include "PlayerTwinStickCharacter.generated.h"

struct FArrowSpawnGroup;
enum class ArrowType : uint8;
enum class PawnState : uint8;
class UPlayerAttributesComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDashEvent);

UCLASS()
class UNREALTOPDOWN_API APlayerTwinStickCharacter : public ATwinStickCharacter, public ICombat
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Arrow")
	ArrowType ArrowType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArrowSpawnGroup")
	TArray<FArrowSpawnGroup> ArrowSpawnGroup;

	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCooldown = 2.f;
	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCost = 12.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float ShootCost = 1.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float AoECost = 50.f;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FDashEvent OnDash;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPlayerAttributesComponent* PlayerAttributesComponent;
	
	UPROPERTY(VisibleAnywhere, Category= "State")
	PawnState PawnState;

	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* ArrowRelease;
	
	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* DashSound;
	
	float DashTimer;

protected:
	APlayerTwinStickCharacter();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void Dash(const FInputActionValue& Value) override;

	virtual void Shoot(const FInputActionValue& Value) override;
	
	virtual void DoShoot(FArrowSpawnGroup ArrowData);
	
	void Die();

public:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void GetDamage_Implementation(float amount) override;

	UPlayerAttributesComponent* GetPlayerAttributesComponent() const { return PlayerAttributesComponent; }
};
