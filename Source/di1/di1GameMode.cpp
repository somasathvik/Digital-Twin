// Copyright Epic Games, Inc. All Rights Reserved.

#include "di1GameMode.h"
#include "di1Character.h"
#include "UObject/ConstructorHelpers.h"

Adi1GameMode::Adi1GameMode()
{
	// set default pawn class to our Blueprinted character
	/* static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	*/
}
