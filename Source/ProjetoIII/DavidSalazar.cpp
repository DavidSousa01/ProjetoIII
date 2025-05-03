#include "ProjetoIII/DavidSalazar.h"
#include "Camera/CameraComponent.h"
#include "DoorScriptBP.h"

// Sets default values
ADavidSalazar::ADavidSalazar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ADavidSalazar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADavidSalazar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADavidSalazar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("Vertical_Movement", this, &ADavidSalazar::Vertical_Movement);
	PlayerInputComponent->BindAxis("Horizontal_Movement", this, &ADavidSalazar::Horizontal_Movement);

	PlayerInputComponent->BindAxis("TurnCameraX", this, &ADavidSalazar::TurnCameraX);
	PlayerInputComponent->BindAxis("TurnCameraY", this, &ADavidSalazar::TurnCameraY);

	PlayerInputComponent->BindAction("OpenDoor", IE_Pressed, this, &ADavidSalazar::OpenDoor);

}

void ADavidSalazar::OpenDoor()
{
	FHitResult HitResult;
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * 200.0f;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor && HitActor->GetClass()->ImplementsInterface(UDoorScriptBP::StaticClass()))
		{
			IDoorScriptBP::Execute_OpenDoor(HitActor); // 'this' is the interactor
		}
	}
}

void ADavidSalazar::Vertical_Movement(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void ADavidSalazar::Horizontal_Movement(float InputValue)
{
	FVector SidewaysDirection = GetActorRightVector();
	AddMovementInput(SidewaysDirection, InputValue);
}

void ADavidSalazar::TurnCameraX(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void ADavidSalazar::TurnCameraY(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

