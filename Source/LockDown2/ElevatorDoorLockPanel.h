// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldInteractable.h"
#include "DoorPanel.h"
#include "LockDown2Character.h"
#include "ElevatorDoorLockPanel.generated.h"

UCLASS()
class LOCKDOWN2_API AElevatorDoorLockPanel : public AWorldInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevatorDoorLockPanel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ADoorPanel * DoorPanel;

	UPROPERTY(EditAnywhere)
		class ALockDown2Character * PlayerCharacter;

	virtual void OnInteract() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
