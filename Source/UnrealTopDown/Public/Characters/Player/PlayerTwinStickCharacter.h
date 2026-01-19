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

UCLASS()
class UNREALTOPDOWN_API APlayerTwinStickCharacter : public ATwinStickCharacter, public ICombat
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ArrowSpawnGroup")
	TArray<FArrowSpawnGroup> ArrowSpawnGroup;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPlayerAttributesComponent* PlayerAttributesComponent;
	UPROPERTY(VisibleAnywhere, Category= "State")
	PawnState PawnState;
	UPROPERTY(VisibleAnywhere, Category = "Arrow")
	ArrowType ArrowType;
	
	float DashTimer;

protected:
	APlayerTwinStickCharacter();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void Dash(const FInputActionValue& Value) override;

	virtual void Shoot(const FInputActionValue& Value) override;

	virtual void AoEAttack(const FInputActionValue& Value) override;

	virtual void GetDamage_Implementation(float amount) override;

	virtual void DoShoot();
	
	void Die();

public:
	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCooldown = 2.f;
	UPROPERTY(EditDefaultsOnly, Category="Attributes|Energy")
	float DashCost = 12.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float ShootCost = 1.f;
	UPROPERTY(EditDefaultsOnly, Category= "Attributes|Energy")
	float AoECost = 50.f;


	void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	
public:
	UPlayerAttributesComponent* GetPlayerAttributesComponent() const { return PlayerAttributesComponent; }

};
