// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorLockPanel.h"
#include "Kismet/GameplayStatics.h"


ADoorLockPanel::ADoorLockPanel() {
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	mesh->SetupAttachment(boxTrigger);
	InputText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("InputText"));
	InputText->SetupAttachment(mesh);

	correctPassword = "1 1 1 1";
	currentPassword = "";
	displayPassword = "";
	inputNumCount = 0;

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

	if (DoorPanel) {
		UE_LOG(LogTemp, Warning, TEXT("Door Panel Attached"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Door NOT Panel Attached"));
	}
}

void ADoorLockPanel::OnInteract()
{
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