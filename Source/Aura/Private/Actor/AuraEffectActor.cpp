// Copyright Code Goblin Games

#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));
}


void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	// Return early if either reference is bad
	if (TargetAbilitySystemComponent == nullptr) return;
	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContext = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpec = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContext);
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());
}