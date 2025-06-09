#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ARaceGameMode.generated.h"

UCLASS()
class PRAKTYKI_API ARaceGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ARaceGameMode();

    void LapCompleted();
    void StartRace();
    void EndRace();

    int32 GetCurrentLap() const;
    int32 GetTotalLaps() const;

protected:
    virtual void BeginPlay() override;

private:
    int32 CurrentLap;
    int32 TotalLaps;
    float RaceStartTime;
};