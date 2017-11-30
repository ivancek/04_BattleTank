// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Ready
};

class UTankBarrel;
class UTankTurret;

// Holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	
	void AimAt(FVector, float);
	void AimAt(FVector);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus AimFiringStatus = EFiringStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	// TODO Remove once done
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	void MoveBarrelAndTurretTowards(FVector);
};
