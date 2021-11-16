// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TerritorialPissingsCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "tpcChien.generated.h"

/**
 * 
 */
UCLASS()
class TERRITORIALPISSINGS_API AtpcChien : public ATerritorialPissingsCharacter
{
	GENERATED_BODY()

protected :

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void Sprint();
	void StopSprint();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprint, meta = (AllowPrivateAccess = "true"))
	bool bSprint = false;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void BeginPlay();

private:
	AActor* aPromeneur;
	
};
