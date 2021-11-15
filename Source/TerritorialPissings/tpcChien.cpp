// Fill out your copyright notice in the Description page of Project Settings.


#include "tpcChien.h"
#include "tpcPromeneuse.h"


void AtpcChien::BeginPlay()
{
	Super::BeginPlay();

	aPromeneur = UGameplayStatics::GetActorOfClass(GetWorld(), AtpcPromeneuse::StaticClass());
}

void AtpcChien::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AtpcChien::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AtpcChien::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AtpcChien::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AtpcChien::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AtpcChien::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AtpcChien::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AtpcChien::OnResetVR);
}


void AtpcChien::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		if (!IsValid(aPromeneur))
			return;

		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aPromeneur->GetActorLocation();
		const FVector vResult = (vLocation + (Direction*Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		if (fResult <= 1000 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void AtpcChien::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction

		if (!IsValid(aPromeneur))
			return;

		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aPromeneur->GetActorLocation();
		const FVector vResult = (vLocation + (Direction * Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		AddMovementInput(Direction, Value);

		//Gestion de l'�loignement avec la laisse.
		if (fResult <= 1000 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}