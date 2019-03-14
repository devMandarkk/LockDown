// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "FoodMachine.generated.h"

/**
 * 
 */
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

	virtual void OnInteract() override;


protected:
	virtual void BeginPlay() override;
};
