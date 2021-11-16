// Fill out your copyright notice in the Description page of Project Settings.


#include "tpcPromeneur.h"
#include "tpcChien.h"

void AtpcPromeneur::BeginPlay()
{
	Super::BeginPlay();

	aChien = UGameplayStatics::GetActorOfClass(GetWorld(), AtpcChien::StaticClass());

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, aChien->GetName());
}

void AtpcPromeneur::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AtpcPromeneur::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AtpcPromeneur::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AtpcPromeneur::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AtpcPromeneur::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AtpcPromeneur::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AtpcPromeneur::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AtpcPromeneur::OnResetVR);
}


void AtpcPromeneur::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value > 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aChien->GetActorLocation();
		const FVector vResult = (vLocation + (Direction * Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		if (fResult <= 1000 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void AtpcPromeneur::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction


		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aChien->GetActorLocation();
		const FVector vResult = (vLocation + (Direction * Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		//Gestion de l'éloignement avec la laisse.
		if (fResult <= 1000 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}
