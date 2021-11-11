// Fill out your copyright notice in the Description page of Project Settings.


#include "cPromeneur.h"

// Sets default values
AcPromeneur::AcPromeneur()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcPromeneur::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcPromeneur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AcPromeneur::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

