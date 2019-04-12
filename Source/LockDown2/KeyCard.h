// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "Camera/CameraComponent.h"
#include "KeyCard.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API AKeyCard : public AWorldInteractable
{
	GENERATED_BODY()
public:

	AKeyCard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* KeyCardMesh;

	UPROPERTY(EditAnywhere)
		AActor * PlayerCamera;

	virtual void OnInteract() override;

};
