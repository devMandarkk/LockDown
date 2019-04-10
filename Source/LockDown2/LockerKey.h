// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "LockerKey.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API ALockerKey : public AWorldInteractable
{
	GENERATED_BODY()

public:
	ALockerKey();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* LockerKeyMesh;

	virtual void OnInteract() override;
	
};
