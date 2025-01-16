// Copyright Code Goblin Games

#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::SetAbilitySystemComponent(TObjectPtr<UAbilitySystemComponent> NewAbilitySystemComponent)
{
	AbilitySystemComponent = NewAbilitySystemComponent;
}

void AAuraCharacterBase::SetAttributeSet(TObjectPtr<UAttributeSet> NewAttributeSet)
{
	AttributeSet = NewAttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
