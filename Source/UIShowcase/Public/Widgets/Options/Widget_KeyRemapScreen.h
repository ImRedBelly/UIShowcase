// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_KeyRemapScreen.generated.h"

class UCommonRichTextBlock;
class FKeyRemapScreenInputPreprocessor;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UISHOWCASE_API UWidget_KeyRemapScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()

public:
	void SetDesiredInputTypeToFilter(ECommonInputType InDesiredInputType);

	DECLARE_DELEGATE_OneParam(FOnKeyRemapScreenKeyPressedDelegate, const FKey& /*PressedKey*/)
	FOnKeyRemapScreenKeyPressedDelegate OnKeyRemapScreenKeyPressed;

	DECLARE_DELEGATE_OneParam(FOnKeyRemapScreenKeySelectCanceledDelegate, const FString& /*CanceledReason*/)
	FOnKeyRemapScreenKeySelectCanceledDelegate OnKeyRemapScreenKeySelectCanceled;

protected:
	//~ Begin UCommonActivatableWidget Interface
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
	//~ End UCommonActivatableWidget Interface

private:
	//***** Bound Widgets ***** //
	UPROPERTY(meta = (BindWidget))
	UCommonRichTextBlock* CommonRichText_RemapMessage;
	//***** Bound Widgets ***** /

	TSharedPtr<FKeyRemapScreenInputPreprocessor> CachedInputPreprocessor;

	ECommonInputType CachedDesiredInputType;

	void OnValidKeyPressedDetected(const FKey& PressedKey);
	void OnKeySelectCanceled(const FString& CanceledReason);

	//Delay a tick to make sure the input key is captured properly before calling the PreDeactivateCallback and deactivating the widget
	void RequestDeactivateWidget(TFunction<void()> PreDeactivateCallback);
};
