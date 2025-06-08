#include "ULapTimerComponent.h"

ULapTimerComponent::ULapTimerComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void ULapTimerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void ULapTimerComponent::StartLap()
{
    LapStartTime = GetWorld()->GetTimeSeconds();
}

void ULapTimerComponent::EndLap()
{
    float EndTime = GetWorld()->GetTimeSeconds();
    LapTimes.Add(EndTime - LapStartTime);
}

float ULapTimerComponent::GetCurrentLapTime() const
{
    return GetWorld()->GetTimeSeconds() - LapStartTime;
}

const TArray<float>& ULapTimerComponent::GetLapTimes() const
{
    return LapTimes;
}