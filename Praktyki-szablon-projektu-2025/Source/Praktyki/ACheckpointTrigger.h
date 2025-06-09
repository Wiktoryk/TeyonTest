#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACheckpointTrigger.generated.h"

UCLASS()
class PRAKTYKI_API ACheckpointTrigger : public AActor
{
    GENERATED_BODY()

public:
    ACheckpointTrigger();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* TriggerBox;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
        const FHitResult& SweepResult);

};