#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DavidSalazar.generated.h"

UCLASS()
class PROJETOIII_API ADavidSalazar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADavidSalazar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OpenDoor();



protected:

	UPROPERTY(EditAnywhere);
	class UCameraComponent* Camera;

	void Vertical_Movement(float InputValue);
	void Horizontal_Movement(float InputValue);

	void TurnCameraX(float InputValue);
	void TurnCameraY(float InputValue);
};
