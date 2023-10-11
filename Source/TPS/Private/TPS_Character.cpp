// Fill out your copyright notice in the Description page of Project Settings.

#include "TPS/Public/TPS_Character.h"

#include "Camera/CameraComponent.h"


// Sets default values
ATPS_Character::ATPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS_CameraComponent"));
	FPSCameraComponent-> bUsePawnControlRotation = true;
	FPSCameraComponent-> SetupAttachment(RootComponent);

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

void ATPS_Character::Jump()
{
	Super::Jump();
}

void ATPS_Character::AddControllerPitchInput(float value)
{
	Super::AddControllerPitchInput(bIsLookInversion? -value : value);
}

void ATPS_Character::StopJumping()
{
	Super::StopJumping();
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

	PlayerInputComponent->BindAxis("LookUp", this, &ATPS_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATPS_Character::Jump);
	PlayerInputComponent->BindAction("StopJumping", IE_Pressed, this, &ATPS_Character::Jump);
}



