#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DoorScriptBP.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UDoorScriptBP : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJETOIII_API IDoorScriptBP
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OpenDoor();

};
