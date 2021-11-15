// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TerritorialPissingsCharacter.h"
#include "tpcPromeneur.generated.h"

/**
 * 
 */
UCLASS()
class TERRITORIALPISSINGS_API AtpcPromeneur : public ATerritorialPissingsCharacter
{
	GENERATED_BODY()

protected:

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
	//ACharacter cChien;
};
