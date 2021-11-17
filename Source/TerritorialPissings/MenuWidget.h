// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TERRITORIALPISSINGS_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected :
	UFUNCTION(BlueprintCallable, Category = Server, Exec)
	void Join(FString sIP);

	UFUNCTION(BlueprintCallable, Category = Server, Exec)
	void Host();
	
};
