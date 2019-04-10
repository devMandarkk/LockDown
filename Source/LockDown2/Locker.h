// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "LockDown2Character.h"
#include "Locker.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleLockerDoor);

UCLASS()
class LOCKDOWN2_API ALocker : public AWorldInteractable
{
	GENERATED_BODY()

public:
	ALocker();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* AnimationPositionPointer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LockerNumMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LockerDoorLockMesh;

	UPROPERTY(EditAnywhere)
	class ALockDown2Character * PlayerCharacter;

	UPROPERTY(BlueprintAssignable)
		FToggleLockerDoor ToggleDoorRequest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DoorOpenDelay;

	bool bIsLockerOpen;

	UPROPERTY(EditAnywhere)
		float AnimationRotateDirection;

	virtual void OnInteract() override;
	virtual void BeginPlay() override;

};
