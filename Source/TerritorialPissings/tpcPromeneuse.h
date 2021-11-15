// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FP_FirstPerson/FP_FirstPersonCharacter.h"
#include "tpcPromeneuse.generated.h"

/**
 * 
 */
UCLASS()
class TERRITORIALPISSINGS_API AtpcPromeneuse : public AFP_FirstPersonCharacter
{
	GENERATED_BODY()
protected:

	bool bSprint = false;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void BeginPlay();

private:
	AActor* aChien;
};
