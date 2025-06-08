#include "ARacePlayerController.h"
#include "Blueprint/UserWidget.h"

void ARacePlayerController::BeginPlay()
{
    Super::BeginPlay();
    bShowMouseCursor = false;
    SetInputMode(FInputModeGameOnly());
}

void ARacePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("Pause", IE_Pressed, this, &ARacePlayerController::PauseGame);
}

void ARacePlayerController::PauseGame()
{
    SetPause(true);
}