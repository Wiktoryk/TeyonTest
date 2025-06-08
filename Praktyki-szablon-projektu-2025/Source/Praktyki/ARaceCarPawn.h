#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ARaceCarPawn.generated.h"

UCLASS()
class ARaceCarPawn : public APawn
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* CarMesh;

    float CurrentForwardInput;
    float CurrentRightInput;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Acceleration = 100000.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float TurnSpeed = 50.0f;

public:
    ARaceCarPawn();
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
};