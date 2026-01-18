#pragma once

#include "CoreMinimal.h"
#include "Variant_TwinStick/TwinStickCharacter.h"
#include "PlayerTwinStickCharacter.generated.h"

enum class PawnState : uint8;
class UPlayerAttributesComponent;

UCLASS()
class UNREALTOPDOWN_API APlayerTwinStickCharacter : public ATwinStickCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPlayerAttributesComponent* PlayerAttributesComponent;
	UPROPERTY(VisibleAnywhere, Category= "State")
	PawnState PawnState;

	float DashTimer;

protected:
	APlayerTwinStickCharacter();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void Dash(const FInputActionValue& Value) override;

	virtual void Shoot(const FInputActionValue& Value) override;

	virtual void AoEAttack(const FInputActionValue& Value) override;

public:
	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCooldown = 2.f;
	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCost = 12.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float ShootCost = 1.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float AoECost = 50.f;

	
public:
	UPlayerAttributesComponent* GetPlayerAttributesComponent() const { return PlayerAttributesComponent; }

};
