#include "URaceGameInstance.h"

void URaceGameInstance::SetTotalLaps(int32 Laps)
{
    TotalLaps = Laps;
}

void URaceGameInstance::SetMaxTime(float Time)
{
    MaxTime = Time;
}

int32 URaceGameInstance::GetTotalLaps() const
{
    return TotalLaps;
}

float URaceGameInstance::GetMaxTime() const
{
    return MaxTime;
}
