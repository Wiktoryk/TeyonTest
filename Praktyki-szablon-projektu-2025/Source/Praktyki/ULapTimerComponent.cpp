#include "ULapTimerComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

ULapTimerComponent::ULapTimerComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void ULapTimerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void ULapTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    /*if (bRaceStarted)
    {
        float CurrentLapTime = GetCurrentLapTime();
    }*/
}

void ULapTimerComponent::StartRace()
{
    bRaceStarted = true;
    RaceStartTime = UGameplayStatics::GetTimeSeconds(GetWorld());
    LapStartTime = RaceStartTime;
    LapTimes.Empty();

    UE_LOG(LogTemp, Log, TEXT("Race started at %f"), RaceStartTime);
}

void ULapTimerComponent::CompleteLap()
{
    if (!bRaceStarted) {
        return;
    }

    float CurrentTime = UGameplayStatics::GetTimeSeconds(GetWorld());
    float LapTime = CurrentTime - LapStartTime;
    LapTimes.Add(LapTime);

    UE_LOG(LogTemp, Log, TEXT("Lap %d completed: %f seconds"), LapTimes.Num(), LapTime);

    LapStartTime = CurrentTime;
}

void ULapTimerComponent::EndRace()
{
    bRaceStarted = false;
    float CombinedLapTime = 0.f;
    for (float time : LapTimes) {
        CombinedLapTime += time;
    }
    UE_LOG(LogTemp, Log, TEXT("Race ended. Total time: %f seconds"), CombinedLapTime);
    UE_LOG(LogTemp, Log, TEXT("Lap times:"));

    for (int32 i = 0; i < LapTimes.Num(); i++)
    {
        UE_LOG(LogTemp, Log, TEXT("Lap %d: %f seconds"), i + 1, LapTimes[i]);
    }
}

float ULapTimerComponent::GetCurrentLapTime() const
{
    if (!bRaceStarted) {
        return 0.f;
    }

    float CurrentTime = UGameplayStatics::GetTimeSeconds(GetWorld());
    return CurrentTime - LapStartTime;
}

float ULapTimerComponent::GetTotalRaceTime() const
{
    if (!bRaceStarted) {
        return 0.f;
    }

    float CurrentTime = UGameplayStatics::GetTimeSeconds(GetWorld());
    return CurrentTime - RaceStartTime;
}

const TArray<float>& ULapTimerComponent::GetLapTimes() const
{
    return LapTimes;
}