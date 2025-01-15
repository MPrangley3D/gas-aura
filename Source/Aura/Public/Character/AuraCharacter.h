// Copyright Code Goblin Games

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> Springarm;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> Camera;
};
