#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"
//#include "EditorDelegates.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "TickableEditorObject.h"

DECLARE_MULTICAST_DELEGATE(FOnAllPendingActorsFinalized);

class FActorFinalizationWatcher : public FTickableEditorObject
{
public:
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FActorFinalizationWatcher, STATGROUP_Tickables);
	}

	virtual void Tick(float DeltaTime) override;

public:
	FOnAllPendingActorsFinalized OnAllPendingActorsFinalized;
	
	void AddActors(const TArray<AActor*>& NewActors);

private:
	TArray<TWeakObjectPtr<AActor>> PendingActors;

	bool IsActorFinalized(AActor* Actor);
};