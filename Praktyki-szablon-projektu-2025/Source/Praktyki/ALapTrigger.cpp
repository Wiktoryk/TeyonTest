#include "ALapTrigger.h"
#include "Components/BoxComponent.h"
#include "ARaceGameMode.h"
#include "Kismet/GameplayStatics.h"

ALapTrigger::ALapTrigger()
{
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALapTrigger::OnOverlapBegin);
}

void ALapTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void ALapTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("PlayerCar"))
    {
        ARaceGameMode* GameMode = Cast<ARaceGameMode>(UGameplayStatics::GetGameMode(this));
        if (GameMode)
        {
            GameMode->LapCompleted();
        }
    }
}