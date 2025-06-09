#include "ARaceHUD.h"
#include "Blueprint/UserWidget.h"

void ARaceHUD::BeginPlay()
{
    Super::BeginPlay();
    ShowStartMenu();
}

void ARaceHUD::ShowStartMenu()
{
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }

    if (StartMenuClass)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), StartMenuClass);
        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

void ARaceHUD::ShowInGameHUD()
{
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }

    if (InGameHUDClass)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), InGameHUDClass);
        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

void ARaceHUD::ShowEndMenu()
{
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }

    if (EndMenuClass)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), EndMenuClass);
        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();
        }
    }
}