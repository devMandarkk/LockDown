// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldInteractable.h"
#include "RegularDoor.h"
#include "DoorPanel.generated.h"

/**
 * 
 */
UCLASS()
class LOCKDOWN2_API ADoorPanel : public AWorldInteractable
{
	GENERATED_BODY()

public:

	//Constructor
	ADoorPanel();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* btnMesh;

	UPROPERTY(EditAnywhere)
	bool isOpen;

	UPROPERTY(EditAnywhere)
	bool IsLocked;

	UPROPERTY(EditAnywhere)
	class ARegularDoor* RegularDoor;

	UPROPERTY(EditAnywhere)
	class ARegularDoor* RegularDoor2;

	virtual void OnInteract() override;
	void UnlockDoor();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
