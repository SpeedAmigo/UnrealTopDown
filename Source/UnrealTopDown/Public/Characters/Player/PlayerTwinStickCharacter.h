#pragma once

#include "CoreMinimal.h"
#include "Variant_TwinStick/TwinStickCharacter.h"
#include "PlayerTwinStickCharacter.generated.h"

class UPlayerAttributesComponent;

UCLASS()
class UNREALTOPDOWN_API APlayerTwinStickCharacter : public ATwinStickCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UPlayerAttributesComponent* PlayerAttributesComponent;

protected:
	APlayerTwinStickCharacter();
	virtual void BeginPlay() override;
	
public:
	UPlayerAttributesComponent* GetPlayerAttributesComponent() const { return PlayerAttributesComponent; }
};
