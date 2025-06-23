// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "FrontendDeveloperSettings.generated.h"

class UWidget_ActivatableBase;
/**
 * 
*/
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Frontend UI Settings"))
class UISHOWCASE_API UFrontendDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
	UPROPERTY(Config, EditAnywhere, Category = "Widget Reference", meta = (ForceInlineRow, Categories = "Frontend.Widget"))
	TMap< FGameplayTag,TSoftClassPtr<UWidget_ActivatableBase> > FrontendWidgetMap;
};
