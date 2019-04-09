// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LockDown2Character.h"
#include "LockDown2Projectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "ExaminableInteractable.h"
#include "DoorPanel.h"
#include "NameTypes.h"
#include "DrawDebugHelpers.h"



DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ALockDown2Character

ALockDown2Character::ALockDown2Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(GetCapsuleComponent());
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	//Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	//FirstPersonCameraComponent->SetupAttachment(Mesh1P);
	FName CameraSocket = TEXT("Head_JNT");
	//FirstPersonCameraComponent->AttachToComponent(Mesh1P, FAttachmentTransformRules::KeepWorldTransform, CameraSocket);
	FirstPersonCameraComponent->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, true), TEXT("Head_JNT"));

	//FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComponent"));
	HoldingComponent->RelativeLocation.X = 100.0f;
	HoldingComponent->RelativeLocation.Y = 100.0f;
	HoldingComponent->RelativeLocation.Z = 100.0f;

	HoldingComponent->SetupAttachment(Mesh1P);

	//Initialize all interactables as null here
	CurrentItem = NULL;
	//DoorPanel = NULL;
	WorldInteractable = NULL;
	CurrentHoveredItem = NULL;
	CurrentSelectedItem = "";

	bCanMove = true;
	bInspecting = false;
	bHasKey = false;
	//UPROPERTY(BlueprintReadWrite)
	bInteractingTerminal = 0;
	bStopMouseRotation = false;
	PlayerAnimationState = EPlayerState::PS_Idle;
}

void ALockDown2Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	PitchMax = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMax;
	PitchMin = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMin;
	Mesh1P->SetHiddenInGame(true);


	if (PlayerAnimationState == EPlayerState::PS_Idle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player in idle state!"));

	}
}

void ALockDown2Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Start = FirstPersonCameraComponent->GetComponentLocation();
	ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	End = (ForwardVector * 200.0f) + Start;

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	if (!bHoldingItem) {
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, DefaultComponentQueryParams, DefaultResponseParam)) {
			if (Hit.GetActor()->GetClass()->IsChildOf(AWorldInteractable::StaticClass())) {
				
				//if the new hit world interactable is different from the previous one... 
				//turn of the previous one before turning on the other one. 
				if (CurrentHoveredItem) {
					if (CurrentHoveredItem != Cast<AWorldInteractable>(Hit.GetActor())) {
						CurrentHoveredItem->OnHoverOff();
					}
				}
				
				CurrentHoveredItem = Cast<AWorldInteractable>(Hit.GetActor());
				CurrentSelectedItem = CurrentHoveredItem->ItemName;
				CurrentHoveredItem->OnHoverOver();
				//UE_LOG(LogTemp, Warning, TEXT("Hovering over a world item %s"), *CurrentSelectedItem);
				

				if (Hit.GetActor()->GetClass()->IsChildOf(AExaminableInteractable::StaticClass())) {
					CurrentItem = Cast <AExaminableInteractable>(Hit.GetActor());
					//currentSelectedItem = CurrentItem->GetName();
				}
				else {
					WorldInteractable = CurrentHoveredItem;
				}
				//if (Hit.GetActor()->GetClass()->IsChildOf(ADoorPanel::StaticClass())) {
				//	DoorPanel = Cast <ADoorPanel>(Hit.GetActor());
				//	//currentSelectedItem = (FString)doorPanel->name;
				//}
			}
			else {
				//The ray hit something but not interactable
				if (CurrentHoveredItem) {
					CurrentHoveredItem->OnHoverOff();
				}
				CurrentSelectedItem = "";
				CurrentItem = NULL;
				//DoorPanel = NULL;
				WorldInteractable = NULL;
			}
			


			//UE_LOG(LogTemp, Warning, TEXT(currentSelectedItem));

		}
		else {
			if (CurrentHoveredItem) {
				CurrentHoveredItem->OnHoverOff();
			}
			CurrentSelectedItem = "";
			CurrentItem = NULL;
			//DoorPanel = NULL;
			WorldInteractable = NULL;


			//drinkMachine = NULL;
		}
	}
	else {
		if (CurrentHoveredItem) {
			CurrentHoveredItem->OnHoverOff();
		}

		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, DefaultComponentQueryParams, DefaultResponseParam)) {
			if (Hit.GetActor()->GetClass()->IsChildOf(APutBackVolumeActor::StaticClass())) {
				CurrentSelectedItem = "Put Back";

			}
		}
		else {
			CurrentSelectedItem = "";

		}
	}


	if (bInspecting) {
		if (bHoldingItem) {
			FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 90.0f, 0.1f));
			HoldingComponent->SetRelativeLocation(FVector(100.0f, 20.0f, 150.0f));
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMax = 179.9000002f;
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMin = -179.9000002f;
			CurrentItem->RotateActor();
		}
		else {
			FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 45.0f, 0.1f));
		}
	}
	else {
		FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 90.0f, 0.1f));

		if (bHoldingItem) {
			HoldingComponent->SetRelativeLocation(FVector(100.0f, 100.0f, 100.0));
		}
	}
}

void ALockDown2Character::UpdateAnimationState(EPlayerState NewAnimationState)
{
	//Hide arms at all times and use pawn rotation for looking.
	//On interaction...
	//Get player character and move it to set position.

	//Show the hands mesh...
	Mesh1P->SetHiddenInGame(false);
	//Change mouse rotation from player to animation
	//FirstPersonCameraComponent->bUsePawnControlRotation = false;
	
	//Then play push button animation one time.
	PlayerAnimationState = NewAnimationState;

	bInteractingTerminal = true;
	bStopMouseRotation = true;

}

void ALockDown2Character::ResetAnimationAndMeshParameters()
{
	Mesh1P->SetHiddenInGame(true);
	//FirstPersonCameraComponent->bUsePawnControlRotation = true;
	bInteractingTerminal = false;
	bStopMouseRotation = false;

}
bool ALockDown2Character::PutBack()
{
	//Make a quick raycast to test to see if its hitting something with class putbackvolume. 
	//If so, hit true. 
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, DefaultComponentQueryParams, DefaultResponseParam)) {
		if (Hit.GetActor()->GetClass()->IsChildOf(APutBackVolumeActor::StaticClass())) {
			return true;
		}
	}
	return false;
}
void ALockDown2Character::OnAction()
{

	if (CurrentItem && !bInspecting) {
		ToggleItemPickup();

	}
	else if (WorldInteractable && !bInspecting) {
		WorldInteractable->OnInteract();
	}
	//if (drinkMachine && !bInspecting) {
	//	drinkMachine->OnInteract();
	//}

}

void ALockDown2Character::OnInspect()
{

	if (bHoldingItem) {
		LastRotation = GetControlRotation();
		ToggleMovement();
	}
	else {
		bInspecting = true;
	}
}

void ALockDown2Character::OnInspectReleased()
{
	if (bInspecting && bHoldingItem) {
		GetController()->SetControlRotation(LastRotation);
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMax = PitchMax;
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMin = PitchMin;
		ToggleMovement();
	}
	else {
		bInspecting = false;
	}
}

void ALockDown2Character::ToggleMovement()
{
	bCanMove = !bCanMove;
	bInspecting = !bInspecting;
	FirstPersonCameraComponent->bUsePawnControlRotation = !FirstPersonCameraComponent->bUsePawnControlRotation;
	bUseControllerRotationYaw = !bUseControllerRotationYaw;
}

void ALockDown2Character::ToggleItemPickup()
{
	if (CurrentItem) {
		bHoldingItem = !bHoldingItem;
		CurrentItem->SetPutBack(PutBack());
		CurrentItem->Pickup();

		if (!bHoldingItem) {
			CurrentItem = NULL;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALockDown2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	// Bind movement events
		PlayerInputComponent->BindAxis("MoveForward", this, &ALockDown2Character::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &ALockDown2Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	//PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("TurnRate", this, &ALockDown2Character::TurnAtRate);
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &ALockDown2Character::LookUpAtRate);

	//Examinable binds.
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &ALockDown2Character::OnAction);

	PlayerInputComponent->BindAction("Inspect", IE_Pressed, this, &ALockDown2Character::OnInspect);
	PlayerInputComponent->BindAction("Inspect", IE_Released, this, &ALockDown2Character::OnInspectReleased);


}

void ALockDown2Character::MoveForward(float Value)
{
	if (!bInteractingTerminal) {
		if (Value != 0.0f && bCanMove)
		{
			// add movement in that direction
			AddMovementInput(GetActorForwardVector(), Value);
			//UE_LOG(LogTemp, Warning, TEXT("movement button pressed"));

		}
		
	}
	
}

void ALockDown2Character::MoveRight(float Value)
{
	if (!bInteractingTerminal) {

		if (Value != 0.0f && bCanMove)
		{
			// add movement in that direction
			AddMovementInput(GetActorRightVector(), Value);
		}
	}
}

void ALockDown2Character::TurnAtRate(float Rate)
{
	//if (!bInteractingTerminal) {
	//	// calculate delta for this frame from the rate information
	//	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	//}
}

void ALockDown2Character::LookUpAtRate(float Rate)
{
	//if (!bInteractingTerminal) {
	//	// calculate delta for this frame from the rate information
	//	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
	//}
}

