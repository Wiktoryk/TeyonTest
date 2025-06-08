#include "ARaceCarPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ARaceCarPawn::ARaceCarPawn() {
    PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    CollisionBox = Cast<UBoxComponent>(RootComponent);
    CollisionBox->SetSimulatePhysics(true);
    CollisionBox->SetEnableGravity(false);
    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    CollisionBox->SetCollisionProfileName(TEXT("PhysicsActor"));
    CollisionBox->SetBoxExtent(FVector(100.f, 50.f, 30.f));
    CollisionBox->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
    CarMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CarMesh"));
    CarMesh->SetupAttachment(RootComponent);
    CarMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    CarMesh->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> CarMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SK_Porsche_911_GT3-R.SK_Porsche_911_GT3-R"));
    if (CarMeshAsset.Succeeded())
    {
        CarMesh->SetSkeletalMesh(CarMeshAsset.Object);
    }
    //static ConstructorHelpers::FObjectFinder<UPhysicsAsset> PhysicsAsset(TEXT("/Script/Engine.PhysicsAsset'/Game/Vehicles/Porsche_911_GT3_R/SK_Porsche_911_GT3-R_PhysicsAsset'"));
    //CarMesh->SetPhysicsAsset(PhysicsAsset.Object);
    //CarMesh->SetSimulatePhysics(true);
    //CarMesh->SetEnableGravity(false);
    //CarMesh->BodyInstance.bUseCCD = true;
    //CarMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //CarMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

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
    }*/
    static ConstructorHelpers::FObjectFinder<UStaticMesh> FrontWheelMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Front_Wheel.SM_Porsche_911_GT3_R_Front_Wheel"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> RearWheelMeshAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Wheel.SM_Porsche_911_GT3_R_Rear_Wheel"));
    class UStaticMeshComponent* FrontRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheelMesh"));
    FrontRightWheelMesh->SetupAttachment(CarMesh, FName("wheel_front_right_spin"));
    if (FrontWheelMeshAsset.Succeeded())
    {
        FrontRightWheelMesh->SetStaticMesh(FrontWheelMeshAsset.Object);
    }
    FrontRightWheelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    class UStaticMeshComponent* FrontLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftWheelMesh"));
    FrontLeftWheelMesh->SetupAttachment(CarMesh, FName("wheel_front_left_spin"));
    if (FrontWheelMeshAsset.Succeeded())
    {
        FrontLeftWheelMesh->SetStaticMesh(FrontWheelMeshAsset.Object);
    }
    FrontLeftWheelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    class UStaticMeshComponent* RearRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RearRightWheelMesh"));
    RearRightWheelMesh->SetupAttachment(CarMesh, FName("wheel_back_right_spin"));
    if (RearWheelMeshAsset.Succeeded())
    {
        RearRightWheelMesh->SetStaticMesh(RearWheelMeshAsset.Object);
    }
    RearRightWheelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    class UStaticMeshComponent* RearLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RearLeftWheelMesh"));
    RearLeftWheelMesh->SetupAttachment(CarMesh, FName("wheel_back_left_spin"));
    if (RearWheelMeshAsset.Succeeded())
    {
        RearLeftWheelMesh->SetStaticMesh(RearWheelMeshAsset.Object);
    }
    RearLeftWheelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 500.f;
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = true;
    SpringArm->bInheritRoll = false;
    SpringArm->SocketOffset = FVector(0.f, 0.f, 100.f);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;
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

    PlayerInputComponent->BindAction("Brake", IE_Pressed, this, &ARaceCarPawn::BrakePressed);
    PlayerInputComponent->BindAction("Brake", IE_Released, this, &ARaceCarPawn::BrakeReleased);

    PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &ARaceCarPawn::HandbrakePressed);
    PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &ARaceCarPawn::HandbrakeReleased);
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
        CurrentSpeed += CurrentForwardInput * Acceleration * DeltaTime;
    }
    else {
        if (CurrentSpeed > 0.f)
        {
            CurrentSpeed -= NaturalDeceleration * DeltaTime;
            CurrentSpeed = FMath::Max(CurrentSpeed, 0.f);
        }
        else if (CurrentSpeed < 0.f)
        {
            CurrentSpeed += NaturalDeceleration * DeltaTime;
            CurrentSpeed = FMath::Min(CurrentSpeed, 0.f);
        }
    }
    if (bIsBraking) {
        if (CurrentSpeed > 0.f)
        {
            CurrentSpeed -= BrakeDeceleration * DeltaTime;
            CurrentSpeed = FMath::Max(CurrentSpeed, 0.f);
        }
    }
    if (bIsHandBraking)
    {
        if (CurrentSpeed > 0.f)
        {
            CurrentSpeed -= HandbrakeDeceleration * DeltaTime;
            CurrentSpeed = FMath::Max(CurrentSpeed, 0.f);
        }
    }
    CurrentSpeed = FMath::Clamp(CurrentSpeed, -MaxSpeed * 0.5f, MaxSpeed);
    if (FMath::Abs(CurrentRightInput) > KINDA_SMALL_NUMBER && FMath::Abs(CurrentSpeed) > 10.f)
    {
        float TurnAmount = CurrentRightInput * TurnSpeedDegreesPerSecond * DeltaTime * (CurrentSpeed / MaxSpeed);
        FRotator CurrentRotation = CollisionBox->GetComponentRotation();
        CurrentRotation.Yaw += TurnAmount;
        CollisionBox->SetWorldRotation(CurrentRotation);
    }
    FVector ForwardVector = CollisionBox->GetForwardVector();
    FVector NewVelocity = ForwardVector * CurrentSpeed;
    CollisionBox->SetPhysicsLinearVelocity(NewVelocity);
}

void ARaceCarPawn::BrakePressed()
{
    bIsBraking = true;
}

void ARaceCarPawn::BrakeReleased()
{
    bIsBraking = false;
}

void ARaceCarPawn::HandbrakePressed()
{
    bIsHandBraking = true;
}

void ARaceCarPawn::HandbrakeReleased()
{
    bIsHandBraking = false;
}