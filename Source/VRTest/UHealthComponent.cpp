#include "UHealthComponent.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"

UUHealthComponent::UUHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UUHealthComponent::OnTakeAnyDamageHandle);
		ComponentOwner->OnTakeRadialDamage.AddDynamic(this, &UUHealthComponent::OnTakeRadialDamage);
	}
}

void UUHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UUHealthComponent::OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser )
{
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("CurrnetHealthValue:  y: %f"),  Health));

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

}

void UUHealthComponent::OnTakeRadialDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, FVector Origin, FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("NewCurrnetHealthValue:  y: %f"),  Health));
	
}


