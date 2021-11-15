// Fill out your copyright notice in the Description page of Project Settings.


#include "Plateforme.h"

// Sets default values
APlateforme::APlateforme()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlateforme::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		vOrigine = this->GetActorLocation();
		FVector vVecteur = vOrigine;
		vVecteur.Z += 1000;
		vCible = vVecteur;

		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

// Called every frame
void APlateforme::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector vLocation = GetActorLocation();
		float fJourneyLength = (vCible - vOrigine).Size();
		float fJourneyTravelled = (vLocation - vOrigine).Size();

		if (fJourneyTravelled >= fJourneyLength)
		{
			FVector vSwap = vOrigine;
			vOrigine = vCible;
			vCible = vSwap;
		}

		this->SetActorLocation(FMath::VInterpTo(vLocation, vCible, DeltaTime, 3.0f));
	}
}

