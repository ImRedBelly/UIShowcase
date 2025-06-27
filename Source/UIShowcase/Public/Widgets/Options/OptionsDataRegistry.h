// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OptionsDataRegistry.generated.h"

class UListDataObject_Base;
/**
 * 
 */
UCLASS()
class UISHOWCASE_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()

public:
	//Gets called by options screen right after the object of type UOptionsDataRegistry is created
	void InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer);

	const TArray<UListDataObject_Base*>& GetRegisteredOptionsTabCollections() const
	{
		return RegisteredOptionsTabCollections;
	}

private:
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitVideoCollectionTab();
	void InitControlCollectionTab();

	TArray<UListDataObject_Base*> RegisteredOptionsTabCollections;
};
