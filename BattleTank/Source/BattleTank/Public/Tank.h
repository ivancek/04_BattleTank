// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Fire();

public:	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3;
	
	// TODO Remove once done
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	

private:
	double LastFireTime = 0;
};
