// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class AFrontendPlayerController;
/**
 * 
 */
UCLASS()
class UISHOWCASE_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	AFrontendPlayerController* GetOwningFrontendPlayerController();

private:
	TWeakObjectPtr<AFrontendPlayerController> CachedOwningFrontendPC;
};
