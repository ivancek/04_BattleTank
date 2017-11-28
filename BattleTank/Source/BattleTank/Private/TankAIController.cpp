// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtPlayer();
}


void ATankAIController::AimAtPlayer()
{
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* TargetTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ControlledTank) { return; }
	if (!TargetTank) { return; }

	ControlledTank->AimAt(TargetTank->GetActorLocation());
	ControlledTank->Fire();
}
