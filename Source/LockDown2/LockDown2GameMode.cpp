// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LockDown2GameMode.h"
#include "LockDown2HUD.h"
#include "LockDown2Character.h"
#include "UObject/ConstructorHelpers.h"

ALockDown2GameMode::ALockDown2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALockDown2HUD::StaticClass();

	hasElevatorKeyCard = false;
}
