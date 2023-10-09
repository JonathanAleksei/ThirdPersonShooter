// Fill out your copyright notice in the Description page of Project Settings.

#include "TPS/Public/TPS_Character.h"

// Sets default values
ATPS_Character::ATPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATPS_Character::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void ATPS_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

// Called every frame
void ATPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATPS_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATPS_Character::MoveRight);
}

