// Fill out your copyright notice in the Description page of Project Settings.


#include "cChien.h"

// Sets default values
AcChien::AcChien()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcChien::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcChien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AcChien::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

