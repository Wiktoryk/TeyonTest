#include "ARaceGameMode.h"
#include "ARaceCarPawn.h"
#include "ARacePlayerController.h"

ARaceGameMode::ARaceGameMode()
{
    TotalLaps = 3;
    CurrentLap = 0;
    RaceStartTime = 0.f;
    DefaultPawnClass = ARaceCarPawn::StaticClass();
    PlayerControllerClass = ARacePlayerController::StaticClass();
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
    float RaceTime = GetWorld()->GetTimeSeconds() - RaceStartTime;
    UE_LOG(LogTemp, Log, TEXT("Race finished in %f seconds."), RaceTime);
}

int32 ARaceGameMode::GetCurrentLap() const
{
    return CurrentLap;
}

int32 ARaceGameMode::GetTotalLaps() const
{
    return TotalLaps;
}