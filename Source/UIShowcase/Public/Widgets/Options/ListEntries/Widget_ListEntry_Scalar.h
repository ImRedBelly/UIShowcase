// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"
#include "Widget_ListEntry_Scalar.generated.h"

class UListDataObject_Scalar;
class UCommonNumericTextBlock;
class UAnalogSlider;

/**
 * 
 */

UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UISHOWCASE_API UWidget_ListEntry_Scalar : public UWidget_ListEntry_Base
{
	GENERATED_BODY()

protected:
	//~ Begin UUserWidget Interface
	virtual void NativeOnInitialized() override;
	//~ Begin UUserWidget Interface


	//~ Begin UWidget_ListEntry_Base Interface
	virtual void OnOwningListDataObjectSet(UListDataObject_Base* InOwningListDataObject) override;
	virtual void OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData,
	                                            EOptionsListDataModifyReason ModifiedReason) override;
	//~ Begin UWidget_ListEntry_Base Interface

private:
	//***** Bound Widgets ***** //
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess = "true"))
	UCommonNumericTextBlock* CommonNumeric_SettingValue;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess = "true"))
	UAnalogSlider* AnalogSlider_SettingSlider;
	//***** Bound Widgets ***** //

	UPROPERTY(Transient)
	UListDataObject_Scalar* CachedOwningScalarDataObject;

	UFUNCTION()
	void OnSliderValueChanged(float Value);
	UFUNCTION()
	void OnSliderMouseCaptureBegin();
};
