#include "ARaceGameMode.h"
#include "ARaceCarPawn.h"
#include "ARacePlayerController.h"
//#include "ARaceHUD2.h"
#include "Kismet/GameplayStatics.h"

ARaceGameMode::ARaceGameMode()
{
    TotalLaps = 3;
    CurrentLap = 0;
    RaceStartTime = 0.f;
    DefaultPawnClass = ARaceCarPawn::StaticClass();
    PlayerControllerClass = ARacePlayerController::StaticClass();
    //HUDClass = ARaceHUD2::StaticClass();
}

void ARaceGameMode::BeginPlay()
{
    Super::BeginPlay();
    StartRace();
}

void ARaceGameMode::StartRace()
{
    RaceStartTime = GetWorld()->GetTimeSeconds();
    CurrentLap = 0;
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) {
        return;
    }

    ARaceCarPawn* Car = Cast<ARaceCarPawn>(PC->GetPawn());
    if (Car && Car->LapTimerComponent)
    {
        Car->LapTimerComponent->StartRace();
    }
}

void ARaceGameMode::LapCompleted()
{
    ++CurrentLap;
    if (CurrentLap >= TotalLaps)
    {
        EndRace();
    }
}

void ARaceGameMode::EndRace()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) {
        return;
    }

    ARaceCarPawn* Car = Cast<ARaceCarPawn>(PC->GetPawn());
    if (Car && Car->LapTimerComponent)
    {
        Car->LapTimerComponent->EndRace();
    }
    UGameplayStatics::SetGamePaused(this, true);
}

int32 ARaceGameMode::GetCurrentLap() const
{
    return CurrentLap;
}

int32 ARaceGameMode::GetTotalLaps() const
{
    return TotalLaps;
}