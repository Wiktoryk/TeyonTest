#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "URaceGameInstance.generated.h"

UCLASS()
class PRAKTYKI_API URaceGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    void SetTotalLaps(int32 Laps);
    void SetMaxTime(float Time);

    int32 GetTotalLaps() const;
    float GetMaxTime() const;

private:
    int32 TotalLaps = 3;
    float MaxTime = 300.f;
};