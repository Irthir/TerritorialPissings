// Copyright Epic Games, Inc. All Rights Reserved.

#include "TerritorialPissingsGameMode.h"
#include "TerritorialPissingsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATerritorialPissingsGameMode::ATerritorialPissingsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT(""));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
