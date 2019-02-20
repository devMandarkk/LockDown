// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "DoorPanel.h"
#include "RegularDoor.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleDoorRequest);

UCLASS()
class LOCKDOWN2_API ARegularDoor : public AWorldInteractable
{
	GENERATED_BODY()

public:

	//Constructor
	ARegularDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* EndPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* StartPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector DoorClosePosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector DoorOpenPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOpen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class ADoorPanel * DoorPanel;

	UPROPERTY(BlueprintAssignable)
	FToggleDoorRequest ToggleDoorRequest;

	void ToggleDoor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
