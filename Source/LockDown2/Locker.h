// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "LockDown2Character.h"
#include "Locker.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API ALocker : public AWorldInteractable
{
	GENERATED_BODY()

public:
	ALocker();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LockerNumMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LockerDoorLockMesh;

	UPROPERTY(EditAnywhere)
	class ALockDown2Character * PlayerCharacter;

	virtual void OnInteract() override;
	virtual void BeginPlay() override;

};
