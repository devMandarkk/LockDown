// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LockDown2Character.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EPlayerState : uint8
{
	PS_Idle 	UMETA(DisplayName = "Idle"),
	PS_ButtonPush 	UMETA(DisplayName = "ButtonPush"),
	PS_ElevatorSwipe UMETA(DisplayName = "ElevatorSwipe")
}; 

class UInputComponent;

UCLASS(config=Game)
class ALockDown2Character : public ACharacter
{
	GENERATED_BODY()

public:
	ALockDown2Character();

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/* -------------------------------------------------------------------------- */
	UPROPERTY(EditAnywhere)
	class USceneComponent* HoldingComponent;

	UPROPERTY(EditAnywhere)
	class AExaminableInteractable* CurrentItem;

	UPROPERTY(EditAnywhere)
	class ADoorPanel* DoorPanel;

	UPROPERTY(EditAnywhere)
	class AWorldInteractable * WorldInteractable;

	UPROPERTY(EditAnywhere)
	class AWorldInteractable* CurrentHoveredItem;

	bool bCanMove;
	bool bHoldingItem;
	bool bInspecting;
	UPROPERTY(BlueprintReadOnly)
	int32 bInteractingTerminal; // this will be used later in BPS
	bool bHasKey;

	float PitchMax;
	float PitchMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString CurrentSelectedItem; //this is being picked up by the HUD

	FVector HoldingComp;
	FRotator LastRotation;

	FVector Start;
	FVector ForwardVector;
	FVector End;

	FHitResult Hit;

	FComponentQueryParams DefaultComponentQueryParams;
	FCollisionResponseParams DefaultResponseParam;

	bool PutBack();

	/*Animation playing related variables!*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EPlayerState PlayerAnimationState;

	//bool bPushButtonAnim;
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationState(EPlayerState NewAnimationState);

	UFUNCTION(BlueprintCallable)
		void ResetAnimationAndMeshParameters();

protected:
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;
	void OnAction();
	void OnInspect();
	void OnInspectReleased();
	void ToggleMovement();
	void ToggleItemPickup();

	/** Handles moving forward/backward */
	void MoveForward(float Val);
	/** Handles stafing movement, left and right */
	void MoveRight(float Val);
	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);
	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface
};

