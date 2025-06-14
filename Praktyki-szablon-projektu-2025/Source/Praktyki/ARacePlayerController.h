#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ARacePlayerController.generated.h"

UCLASS()
class PRAKTYKI_API ARacePlayerController : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;

private:
    void PauseGame();
};