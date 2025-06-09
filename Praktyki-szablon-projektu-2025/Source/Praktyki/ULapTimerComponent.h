#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ULapTimerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRAKTYKI_API ULapTimerComponent : public UActorComponent
{
    GENERATED_BODY()

    bool bRaceStarted = false;
    float RaceStartTime = 0.f;
    float LapStartTime = 0.f;
    TArray<float> LapTimes;
public:
    ULapTimerComponent();

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void StartRace();
    void CompleteLap();
    void EndRace();

    float GetCurrentLapTime() const;
    float GetTotalRaceTime() const;
    const TArray<float>& GetLapTimes() const;

protected:
    virtual void BeginPlay() override;
};