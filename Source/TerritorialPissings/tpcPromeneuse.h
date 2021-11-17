// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FP_FirstPerson/FP_FirstPersonCharacter.h"
#include "cablecomponent.h"
#include "tpcPromeneuse.generated.h"

/**
 * 
 */
UCLASS()
class TERRITORIALPISSINGS_API AtpcPromeneuse : public AFP_FirstPersonCharacter
{
	GENERATED_BODY()
public: 
	AtpcPromeneuse();

	virtual void Tick(float DeltaTime) override;

protected:

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCableComponent* cable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprint, meta = (AllowPrivateAccess = "true"))
	bool bSprint = false;


	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void Sprint();
	void StopSprint();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void BeginPlay();

private:
	AActor* aChien;
};
