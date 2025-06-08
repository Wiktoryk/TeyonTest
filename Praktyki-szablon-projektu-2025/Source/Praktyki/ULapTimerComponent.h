#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ULapTimerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ULapTimerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    ULapTimerComponent();

    void StartLap();
    void EndLap();

    float GetCurrentLapTime() const;
    const TArray<float>& GetLapTimes() const;

protected:
    virtual void BeginPlay() override;

private:
    float LapStartTime;
    TArray<float> LapTimes;
};