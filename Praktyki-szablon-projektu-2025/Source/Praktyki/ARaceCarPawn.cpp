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
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MainBodyAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Main_Body.SM_Porsche_911_GT3_R_Main_Body"));
    class UStaticMeshComponent* MainBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainBodyMesh"));
    MainBodyMesh->SetupAttachment(CarMesh, FName("SK_Porsche_911_Gt3_R1"));
    if (MainBodyAsset.Succeeded())
    {
        MainBodyMesh->SetStaticMesh(MainBodyAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BootRearAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Boot.SM_Porsche_911_GT3_R_Rear_Boot"));
    class UStaticMeshComponent* BootRearMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BootRearMesh"));
    BootRearMesh->SetupAttachment(CarMesh, FName("boot_rear"));
    if (BootRearAsset.Succeeded())
    {
        BootRearMesh->SetStaticMesh(BootRearAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BumperFrontAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Front_Bumper.SM_Porsche_911_GT3_R_Front_Bumper"));
    class UStaticMeshComponent* BumperFrontMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BumperFrontMesh"));
    BumperFrontMesh->SetupAttachment(CarMesh, FName("bumper_front"));
    if (BumperFrontAsset.Succeeded())
    {
        BumperFrontMesh->SetStaticMesh(BumperFrontAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BumperRearAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Bumper.SM_Porsche_911_GT3_R_Rear_Bumper"));
    class UStaticMeshComponent* BumperRearMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BumperRearMesh"));
    BumperRearMesh->SetupAttachment(CarMesh, FName("bumper_rear"));
    if (BumperRearAsset.Succeeded())
    {
        BumperRearMesh->SetStaticMesh(BumperRearAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DiffuserBackAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Diffuser.SM_Porsche_911_GT3_R_Rear_Diffuser"));
    class UStaticMeshComponent* DiffuserBackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DiffuserBackMesh"));
    DiffuserBackMesh->SetupAttachment(CarMesh, FName("diffuser_back"));
    if (DiffuserBackAsset.Succeeded())
    {
        DiffuserBackMesh->SetStaticMesh(DiffuserBackAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorLeftAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Door_Left.SM_Porsche_911_GT3_R_Door_Left"));
    class UStaticMeshComponent* DoorLeftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeftMesh"));
    DoorLeftMesh->SetupAttachment(CarMesh, FName("door_left"));
    if (DoorLeftAsset.Succeeded())
    {
        DoorLeftMesh->SetStaticMesh(DoorLeftAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorRightAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Door_Right.SM_Porsche_911_GT3_R_Door_Right"));
    class UStaticMeshComponent* DoorRightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRightMesh"));
    DoorRightMesh->SetupAttachment(CarMesh, FName("door_right"));
    if (DoorRightAsset.Succeeded())
    {
        DoorRightMesh->SetStaticMesh(DoorRightAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> HoodFrontAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Front_Hood.SM_Porsche_911_GT3_R_Front_Hood"));
    class UStaticMeshComponent* HoodFrontMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HoodFrontMesh"));
    HoodFrontMesh->SetupAttachment(CarMesh, FName("hood_front"));
    if (HoodFrontAsset.Succeeded())
    {
        HoodFrontMesh->SetStaticMesh(HoodFrontAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SpoilerBackAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Rear_Spoiler.SM_Porsche_911_GT3_R_Rear_Spoiler"));
    class UStaticMeshComponent* SpoilerBackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpoilerBackMesh"));
    SpoilerBackMesh->SetupAttachment(CarMesh, FName("spoiler_back"));
    if (SpoilerBackAsset.Succeeded())
    {
        SpoilerBackMesh->SetStaticMesh(SpoilerBackAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MirrorLeftAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Wing_Mirror_Left.SM_Porsche_911_GT3_R_Wing_Mirror_Left"));
    class UStaticMeshComponent* MirrorLeftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MirrorLeftMesh"));
    MirrorLeftMesh->SetupAttachment(CarMesh, FName("wing_mirror_left"));
    if (MirrorLeftAsset.Succeeded())
    {
        MirrorLeftMesh->SetStaticMesh(MirrorLeftAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MirrorRightAsset(TEXT("/Game/Vehicles/Porsche_911_GT3_R/SM_Porsche_911_GT3_R_Wing_Mirror_Right.SM_Porsche_911_GT3_R_Wing_Mirror_Right"));
    class UStaticMeshComponent* MirrorRightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MirrorRightMesh"));
    MirrorRightMesh->SetupAttachment(CarMesh, FName("wing_mirror_right"));
    if (MirrorRightAsset.Succeeded())
    {
        MirrorRightMesh->SetStaticMesh(MirrorRightAsset.Object);
    }
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

    LapTimerComponent = CreateDefaultSubobject<ULapTimerComponent>(TEXT("LapTimerComponent"));
    Tags.Add(TEXT("PlayerCar"));
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

    CheckGroundMaterial(DeltaTime);

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

void ARaceCarPawn::SetIsOnTrack(bool bOnTrack)
{
    bIsOnTrack = bOnTrack;
}

void ARaceCarPawn::ResetLapInvalidation()
{
    bLapInvalidated = false;
}

bool ARaceCarPawn::IsLapInvalidated() const
{
    return bLapInvalidated;
}

void ARaceCarPawn::CheckGroundMaterial(float DeltaTime)
{
    FVector Start = CarMesh->GetComponentLocation();
    FVector End = Start - FVector(0, 0, 1000.0f);

    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.bReturnPhysicalMaterial = true;
    QueryParams.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECC_WorldStatic,
        QueryParams
    );

    if (bHit)
    {
        UPhysicalMaterial* HitPhysMat = HitResult.PhysMaterial.Get();

        if (HitPhysMat)
        {
            CurrentPhysicalMaterial = HitPhysMat;

            FString MaterialName = HitPhysMat->GetName();
            UE_LOG(LogTemp, Log, TEXT("Current ground material: %s"), *MaterialName);

            if (MaterialName.Contains("Grass"))
            {
                OffTrackTime += DeltaTime;

                if (OffTrackTime > MaxAllowedOffTrackTime && !bLapInvalidated)
                {
                    bLapInvalidated = true;
                    UE_LOG(LogTemp, Warning, TEXT("Lap invalidated — too long off-track!"));
                }
            }
            else
            {
                OffTrackTime = 0.0f;
            }
        }
    }
}