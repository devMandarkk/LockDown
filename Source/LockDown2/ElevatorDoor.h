// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDoorClass.h"
#include "GameFramework/Actor.h"
#include "ElevatorDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleElevatorDoor);

UCLASS()
class LOCKDOWN2_API AElevatorDoor : public ABaseDoorClass
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevatorDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * DoorRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * DoorLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsOpen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class ADoorPanel * DoorPanel;

	UPROPERTY(BlueprintAssignable)
		FToggleElevatorDoor ToggleDoorRequest;

	virtual void ToggleDoor() override;

	virtual void BeginPlay() override;

};
