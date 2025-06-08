#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "ARaceCarPawn.generated.h"

UCLASS()
class ARaceCarPawn : public APawn
{
    GENERATED_BODY()

    UBoxComponent* CollisionBox;
    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* CarMesh;

    float CurrentForwardInput{};
    float CurrentRightInput{};

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Acceleration = 100000.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float TurnTorque = 1000000.f;;

public:
    ARaceCarPawn();
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
};