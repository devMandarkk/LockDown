// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDoorClass.h"
#include "DoorPanel.h"
#include "LockerRoomDoor.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleLockerRoomDoor);

UCLASS()
class LOCKDOWN2_API ALockerRoomDoor : public ABaseDoorClass
{
	GENERATED_BODY()
	
public:

	ALockerRoomDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * DoorRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * DoorLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsOpen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class ADoorPanel * DoorPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DoorMoveDistance;

	UPROPERTY(BlueprintAssignable)
		FToggleLockerRoomDoor ToggleDoorRequest;

	UPROPERTY(BlueprintReadOnly)
		FVector RightDoorClosePosition;

	UPROPERTY(BlueprintReadOnly)
		FVector RightDoorOpenPosition;

	UPROPERTY(BlueprintReadOnly)
		FVector LeftDoorClosePosition;

	UPROPERTY(BlueprintReadOnly)
		FVector LeftDoorOpenPosition;

	virtual void ToggleDoor() override;

	virtual void BeginPlay() override;
};
