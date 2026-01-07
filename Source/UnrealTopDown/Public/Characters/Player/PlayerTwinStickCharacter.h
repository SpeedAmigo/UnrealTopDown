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

protected:
	APlayerTwinStickCharacter();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void Dash(const FInputActionValue& Value) override;
	
public:
	UPlayerAttributesComponent* GetPlayerAttributesComponent() const { return PlayerAttributesComponent; }

private:
	float DashCooldown;
};
