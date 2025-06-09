#include "ALapTrigger.h"
#include "Components/BoxComponent.h"
#include "ARaceGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ARaceCarPawn.h"

ALapTrigger::ALapTrigger()
{
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALapTrigger::OnOverlapBegin);
    TriggerBox->SetBoxExtent(FVector(10.f, 200.f, 30.f));
}

void ALapTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void ALapTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag(TEXT("PlayerCar")))
    {
        ARaceCarPawn* Car = Cast<ARaceCarPawn>(OtherActor);
        if (Car && Car->CanFinishLap())
        {
            if (Car->LapTimerComponent)
            {
                Car->LapTimerComponent->CompleteLap();
                Car->SetFinishLap(false);
            }
            ARaceGameMode* GameMode = Cast<ARaceGameMode>(UGameplayStatics::GetGameMode(this));
            if (GameMode)
            {
                GameMode->LapCompleted();
            }
        }
    }
}