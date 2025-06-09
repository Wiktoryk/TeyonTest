#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "ULapTimerComponent.h"
#include "ARaceCarPawn.generated.h"

UCLASS()
class PRAKTYKI_API ARaceCarPawn : public APawn
{
    GENERATED_BODY()

    UBoxComponent* CollisionBox;
    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* CarMesh;
    UPROPERTY(VisibleAnywhere, Category = Camera)
    class USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere, Category = Camera)
    class UCameraComponent* Camera;

    float CurrentForwardInput{};
    float CurrentRightInput{};

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Acceleration = 1000.0f;

    bool bIsBraking = false;
    bool bIsHandBraking = false;

    float CurrentSpeed = 0.f;
    float MaxSpeed = 5000.f;
    float BrakeDeceleration = 4000.f;
    float HandbrakeDeceleration = 6000.f;
    float NaturalDeceleration = 500.f;
    float TurnSpeedDegreesPerSecond = 45.f;

    float OffTrackTime = 0.0f;
    float MaxAllowedOffTrackTime = 4.0f;
    bool bIsOnTrack = true;
    bool bLapInvalidated = false;
    UPhysicalMaterial* CurrentPhysicalMaterial = nullptr;

public:
    ARaceCarPawn();
    virtual void Tick(float DeltaTime) override;
    bool IsLapInvalidated() const;
    void ResetLapInvalidation();

    UPROPERTY(VisibleAnywhere, Category = "Race")
    ULapTimerComponent* LapTimerComponent;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);

    void BrakePressed();
    void BrakeReleased();
    void HandbrakePressed();
    void HandbrakeReleased();
    void SetIsOnTrack(bool bOnTrack);
    void CheckGroundMaterial(float deltaTime);
};