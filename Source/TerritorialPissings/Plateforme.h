// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Plateforme.generated.h"

UCLASS()
class TERRITORIALPISSINGS_API APlateforme : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlateforme();
	FVector vOrigine;
	FVector vCible;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
