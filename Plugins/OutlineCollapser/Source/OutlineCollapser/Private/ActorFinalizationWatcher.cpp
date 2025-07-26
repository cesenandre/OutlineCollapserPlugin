#include "ActorFinalizationWatcher.h" 

void FActorFinalizationWatcher::Tick(float DeltaTime)
{
	bool bHasRemoved = false;
	for (int32 i = PendingActors.Num() - 1; i >= 0; --i)
	{
		AActor* Actor = PendingActors[i].Get();

		if (!IsValid(Actor) || Actor->IsPendingKillPending())
		{
			PendingActors.RemoveAt(i);
			bHasRemoved = true;
			continue;
		}

		if (IsActorFinalized(Actor))
		{
			PendingActors.RemoveAt(i);
			bHasRemoved = true;
		}
	}

	if (bHasRemoved && PendingActors.IsEmpty())
	{
		OnAllPendingActorsFinalized.Broadcast();
	}
}

void FActorFinalizationWatcher::AddActors(const TArray<AActor*>& NewActors)
{
	PendingActors.Append(NewActors);
}

bool FActorFinalizationWatcher::IsActorFinalized(AActor* Actor)
{
	return IsValid(Actor)
		&& !Actor->IsPendingKillPending()
		&& Actor->GetRootComponent()
		&& Actor->GetRootComponent()->IsRegistered()
		&& !Actor->HasAnyFlags(RF_Transient); // opzionale: ignora attori temporanei
}