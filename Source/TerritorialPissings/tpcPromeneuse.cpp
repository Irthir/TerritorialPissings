// Fill out your copyright notice in the Description page of Project Settings.


#include "tpcPromeneuse.h"
#include "tpcChien.h"


AtpcPromeneuse::AtpcPromeneuse()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	cable = CreateDefaultSubobject<UCableComponent>(TEXT("Cable"));
	cable->SetupAttachment(RootComponent);
}

void AtpcPromeneuse::BeginPlay()
{
	Super::BeginPlay();

	aChien = UGameplayStatics::GetActorOfClass(GetWorld(), AtpcChien::StaticClass());
}

void AtpcPromeneuse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AtpcPromeneuse::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AtpcPromeneuse::Sprint);

	PlayerInputComponent->BindAxis("MoveForward", this, &AtpcPromeneuse::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AtpcPromeneuse::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AtpcPromeneuse::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AtpcPromeneuse::LookUpAtRate);


	// handle touch devices
	//PlayerInputComponent->BindTouch(IE_Pressed, this, &AtpcPromeneuse::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &APawn::TouchStopped);

	// VR headset functionality
	//PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &APawn::OnResetVR);
}


void AtpcPromeneuse::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value > 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		if (!IsValid(aChien))
			return;

		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aChien->GetActorLocation();
		const FVector vResult = (vLocation + (Direction * Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		if (fResult <= 1200 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void AtpcPromeneuse::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction

		if (!IsValid(aChien))
			return;

		const FVector vLocation = this->GetActorLocation();
		const FVector vCible = aChien->GetActorLocation();
		const FVector vResult = (vLocation + (Direction * Value));

		float fDistance = FVector::Distance(vLocation, vCible);
		float fResult = FVector::Distance(vResult, vCible);

		//Gestion de l'éloignement avec la laisse.
		if (fResult <= 1200 || fResult < fDistance || bSprint)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void AtpcPromeneuse::Sprint()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Sprint"));
	bSprint = true;

	FTimerHandle UniqueHandle;
	FTimerDelegate SprintDelegate = FTimerDelegate::CreateUObject(this, &AtpcPromeneuse::StopSprint);
	GetWorldTimerManager().SetTimer(UniqueHandle, SprintDelegate, 1.f, false);
}


void AtpcPromeneuse::StopSprint()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("StopSprint"));
	bSprint = false;
}