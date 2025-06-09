#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ALapTrigger.generated.h"

UCLASS()
class PRAKTYKI_API ALapTrigger : public AActor
{
    GENERATED_BODY()

public:
    ALapTrigger();

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