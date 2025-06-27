// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionScreen.generated.h"

class UFrontendTabListWidgetBase;
class UOptionsDataRegistry;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class UISHOWCASE_API UWidget_OptionScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()

protected:
	//~ Begin UUserWidget InterfaceMore actions
	virtual void NativeOnInitialized() override;
	//~ End UUserWidget Interface

	//~ Begin UCommonActivatableWidget Interface
	virtual void NativeOnActivated() override;
	//~ End UCommonActivatableWidget Interface

private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();

	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();

	UFUNCTION()
	void OnOptionsTabSelected(FName TabId);
	
	//***** Bound Widgets ***** //
	UPROPERTY(meta = (BindWidget))
	UFrontendTabListWidgetBase* TabListWidget_OptionsTabs;
	//***** Bound Widgets ***** //

	//Handle the creation of data in the options screen. Direct access to this variable is forbidden
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category = "Frontend Options Screen",
		meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;

	FUIActionBindingHandle ResetActionHandle;
};
