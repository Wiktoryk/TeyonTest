#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ARaceHUD.generated.h"

UCLASS()
class PRAKTYKI_API ARaceHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    void ShowStartMenu();
    void ShowInGameHUD();
    void ShowEndMenu();

protected:
    UPROPERTY(EditDefaultsOnly, Category = UI)
    TSubclassOf<class UUserWidget> StartMenuClass;

    UPROPERTY(EditDefaultsOnly, Category = UI)
    TSubclassOf<class UUserWidget> InGameHUDClass;

    UPROPERTY(EditDefaultsOnly, Category = UI)
    TSubclassOf<class UUserWidget> EndMenuClass;

private:
    UPROPERTY()
    UUserWidget* CurrentWidget;
};