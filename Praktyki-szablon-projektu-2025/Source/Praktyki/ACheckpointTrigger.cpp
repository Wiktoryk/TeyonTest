#include "ACheckpointTrigger.h"
#include "Components/BoxComponent.h"
#include "ARaceGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ARaceCarPawn.h"

ACheckpointTrigger::ACheckpointTrigger()
{
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointTrigger::OnOverlapBegin);
    TriggerBox->SetBoxExtent(FVector(10.f, 200.f, 30.f));
}

void ACheckpointTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void ACheckpointTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag(TEXT("PlayerCar")))
    {
        ARaceCarPawn* Car = Cast<ARaceCarPawn>(OtherActor);
        if (Car)
        {
            Car->SetFinishLap(true);
        }
    }
}