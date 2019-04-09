// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorLockPanel.h"
#include "Kismet/GameplayStatics.h"


ADoorLockPanel::ADoorLockPanel() {
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(SceneComponent);
	InputText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("InputText"));
	InputText->SetupAttachment(mesh);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(mesh);

	correctPassword = "1 1 1 1";
	currentPassword = "";
	displayPassword = "";
	inputNumCount = 0;

	bSwitchCamera = false;
	//InputText->SetText(displayPassword);

}

void ADoorLockPanel::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController) {
		EnableInput(PlayerController);
		InputComponent->BindAction("One", IE_Pressed, this, &ADoorLockPanel::OnOnePressed);
		InputComponent->BindAction("Two", IE_Pressed, this, &ADoorLockPanel::OnTwoPressed);
		InputComponent->BindAction("Three", IE_Pressed, this, &ADoorLockPanel::OnThreePressed);
		InputComponent->BindAction("Four", IE_Pressed, this, &ADoorLockPanel::OnFourPressed);
		InputComponent->BindAction("Five", IE_Pressed, this, &ADoorLockPanel::OnFivePressed);
		InputComponent->BindAction("Six", IE_Pressed, this, &ADoorLockPanel::OnSixPressed);
		InputComponent->BindAction("Seven", IE_Pressed, this, &ADoorLockPanel::OnSevenPressed);
		InputComponent->BindAction("Eight", IE_Pressed, this, &ADoorLockPanel::OnEightPressed);
		InputComponent->BindAction("Nine", IE_Pressed, this, &ADoorLockPanel::OnNinePressed);
	}
	this->ToggleCamera.AddDynamic(this, &ADoorLockPanel::CameraToggle);

	if (DoorPanel) {
		UE_LOG(LogTemp, Warning, TEXT("Door Panel Attached"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Door NOT Panel Attached"));
	}
}

void ADoorLockPanel::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger entered"));
	//bSwitchCamera = true;
	//ToggleCamera.Broadcast();

}

void ADoorLockPanel::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger exited"));
	//bSwitchCamera = false;
	//ToggleCamera.Broadcast();
}
void ADoorLockPanel::CameraToggle()
{
	UE_LOG(LogTemp, Warning, TEXT("Camera Toggle firing through events"));
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	//TimeToNextCameraChange -= DeltaTime;
	//if (TimeToNextCameraChange <= 0.0f)
	//{
		//TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		//FMinimalViewInfo * testView = NULL;
			//camera->GetCameraView(.1f, testView);
		if ((OurPlayerController->GetViewTarget() != PlayerCamera) && (PlayerCamera != nullptr) && !bSwitchCamera)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Time to switch Camera to person"));

			// Cut instantly to camera one.
			OurPlayerController->SetViewTargetWithBlend(PlayerCamera, SmoothBlendTime);

			ALockDown2Character * PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			if (PlayerCharacter) {
				PlayerCharacter->bInteractingTerminal = 0;
				PlayerCharacter->bStopMouseRotation = false;
			}
		}
		else if ((OurPlayerController->GetViewTarget() != this) && (this != nullptr) && bSwitchCamera)
		{
			UE_LOG(LogTemp, Warning, TEXT("Time to switch Camera to panel"));

			// Blend smoothly to camera two.
			OurPlayerController->SetViewTargetWithBlend(this, SmoothBlendTime);
			ALockDown2Character * PlayerCharacter = Cast<ALockDown2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			if (PlayerCharacter) {
				PlayerCharacter->bInteractingTerminal = 1;
				PlayerCharacter->bStopMouseRotation = true;
			}
		}
	}
}

void ADoorLockPanel::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("interacting virtuall"));
	bSwitchCamera = !bSwitchCamera;
	ToggleCamera.Broadcast();

}

void ADoorLockPanel::UpdateUIAndCheckPassword()
{

	displayPassword += "X";

	InputText->SetText(displayPassword);

	if (inputNumCount >= 4) {
		//immediately reset the UI
		//InputText->SetText("");
		//check password for correct password.
		if (currentPassword.Equals(correctPassword))
		{
			UE_LOG(LogTemp, Warning, TEXT("password matches"));
			//Unlock the door.
			DoorPanel->UnlockDoor();
			//reset the password counter
			//reset the current string. 
			currentPassword = "";
			displayPassword = "";
			inputNumCount = 0;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("password wrong"));
			//reset the password counter
			//reset the current string. 
			currentPassword = "";
			displayPassword = "";
			inputNumCount = 0;
		}
	}
	else {
		currentPassword += " ";
		displayPassword += " ";
	}

}

void ADoorLockPanel::OnOnePressed()
{
	inputNumCount++;
	currentPassword += "1";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnTwoPressed()
{
	inputNumCount++;
	currentPassword += "2";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnThreePressed()
{
	inputNumCount++;
	currentPassword += "3";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnFourPressed()
{
	inputNumCount++;
	currentPassword += "4";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnFivePressed()
{
	inputNumCount++;
	currentPassword += "5";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnSixPressed()
{
	inputNumCount++;
	currentPassword += "6";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnSevenPressed()
{
	inputNumCount++;
	currentPassword += "7";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnEightPressed()
{
	inputNumCount++;
	currentPassword += "8";
	UpdateUIAndCheckPassword();
}

void ADoorLockPanel::OnNinePressed()
{
	inputNumCount++;
	currentPassword += "9";
	UpdateUIAndCheckPassword();
}

