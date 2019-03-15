// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "FoodMachine.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleFoodMachineDoorRequest);

UCLASS()
class LOCKDOWN2_API AFoodMachine : public AWorldInteractable
{
	GENERATED_BODY()
	
public:

	AFoodMachine();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * FoodMachine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * FoodMachineCover;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DoorOpenPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DoorClosePosition;

	UPROPERTY(BlueprintAssignable)
		FToggleFoodMachineDoorRequest ToggleDoorRequest;

	float DoorMoveDistance;

	virtual void OnInteract() override;


protected:
	virtual void BeginPlay() override;
};
