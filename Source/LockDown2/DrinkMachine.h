// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "DrinkMachine.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleDrinkMachineDoorRequest);

UCLASS()
class LOCKDOWN2_API ADrinkMachine : public AWorldInteractable
{
	GENERATED_BODY()
	
public:	
	ADrinkMachine();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* DrinkMachine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* DrinkMachineCover;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DoorOpenPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DoorClosePosition;

	UPROPERTY(BlueprintAssignable)
		FToggleDrinkMachineDoorRequest ToggleDoorRequest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DoorMoveDistance;

	virtual void OnInteract() override;

protected:
	virtual void BeginPlay() override;

};
