// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "DrinkMachine.generated.h"

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

	virtual void OnInteract() override;

protected:
	virtual void BeginPlay() override;

};
