// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = Cast<ATank>(GetPawn());
	AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayAgainstPlayer();
}


void ATankAIController::PlayAgainstPlayer()
{
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* TargetTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ensure(ControlledTank)) { return; }
	if (!ensure(TargetTank)) { return; }

	AimingComponent->AimAt(TargetTank->GetActorLocation());
	ControlledTank->Fire();
	MoveToActor(TargetTank, AcceptanceRadius);
}
