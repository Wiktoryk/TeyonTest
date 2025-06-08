#include "ARaceCarPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ARaceCarPawn::ARaceCarPawn() {
    PrimaryActorTick.bCanEverTick = true;
    CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
    RootComponent = CarMesh;
    CarMesh->SetSimulatePhysics(true);
    CarMesh->SetEnableGravity(true);
    CarMesh->BodyInstance.bUseCCD = true;
    CarMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CarMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Main_Body.SM_Porsche_911_GT3_R_Main_Body"));
    if (CarMeshAsset.Succeeded())
    {
        CarMesh->SetStaticMesh(CarMeshAsset.Object);
    }

    /*class USkeletalMeshComponent* VehicleMesh = GetMesh();
    VehicleMesh->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> VehicleMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SK_Porsche_911_GT3-R.SK_Porsche_911_GT3-R"));
    if (VehicleMeshAsset.Succeeded())
    {
        VehicleMesh->SetSkeletalMesh(VehicleMeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not load Vehicle SkeletalMesh!"));
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> FrontWheelMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Front_Wheel.SM_Porsche_911_GT3_R_Front_Wheel"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> RearWheelMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Wheel.SM_Porsche_911_GT3_R_Rear_Wheel"));
    FrontRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheelMesh"));
    FrontRightWheelMesh->SetupAttachment(VehicleMesh, FName("wheel_front_right_spin"));
    if (FrontWheelMeshAsset.Succeeded())
    {
        FrontRightWheelMesh->SetStaticMesh(FrontWheelMeshAsset.Object);
    }

    FrontLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftWheelMesh"));
    FrontLeftWheelMesh->SetupAttachment(VehicleMesh, FName("wheel_front_left_spin"));
    if (FrontWheelMeshAsset.Succeeded())
    {
        FrontLeftWheelMesh->SetStaticMesh(FrontWheelMeshAsset.Object);
    }

    RearRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RearRightWheelMesh"));
    RearRightWheelMesh->SetupAttachment(VehicleMesh, FName("wheel_back_right_spin"));
    if (RearWheelMeshAsset.Succeeded())
    {
        RearRightWheelMesh->SetStaticMesh(RearWheelMeshAsset.Object);
    }

    RearLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RearLeftWheelMesh"));
    RearLeftWheelMesh->SetupAttachment(VehicleMesh, FName("wheel_back_left_spin"));
    if (RearWheelMeshAsset.Succeeded())
    {
        RearLeftWheelMesh->SetStaticMesh(RearWheelMeshAsset.Object);
    }*/
}

void ARaceCarPawn::BeginPlay()
{
    Super::BeginPlay();
}

void ARaceCarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &ARaceCarPawn::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ARaceCarPawn::MoveRight);
}

void ARaceCarPawn::MoveForward(float Value)
{
    CurrentForwardInput = Value;
}

void ARaceCarPawn::MoveRight(float Value)
{
    CurrentRightInput = Value;
}

void ARaceCarPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (FMath::Abs(CurrentForwardInput) > KINDA_SMALL_NUMBER)
    {
        FVector ForceDirection = CarMesh->GetForwardVector();
        CarMesh->AddForce(ForceDirection * CurrentForwardInput * Acceleration);
    }

    if (FMath::Abs(CurrentRightInput) > KINDA_SMALL_NUMBER)
    {
        FRotator CurrentRotation = CarMesh->GetComponentRotation();
        CurrentRotation.Yaw += CurrentRightInput * TurnSpeed * DeltaTime;
        CarMesh->SetWorldRotation(CurrentRotation);
    }
}