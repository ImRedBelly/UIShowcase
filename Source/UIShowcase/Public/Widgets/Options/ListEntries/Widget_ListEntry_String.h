// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"
#include "Widget_ListEntry_String.generated.h"

class UListDataObject_String;
class UFrontendCommonRotator;
class UFrontendCommonButtonBase;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UISHOWCASE_API UWidget_ListEntry_String : public UWidget_ListEntry_Base
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	
	//~ End UWidget_ListEntry_Base Interface
	virtual void OnOwningListDataObjectSet(UListDataObject_Base* InOwningListDataObject) override;
	virtual void OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData,
	                                            EOptionsListDataModifyReason ModifiedReason) override;
	virtual void OnToggleEditableState(bool bIsEditable) override;
	//~ End UWidget_ListEntry_Base Interface

private:
	//***** Bound Widgets ***** //
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess = "true"))
	UFrontendCommonButtonBase* CommonButton_PreviousOption;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess = "true"))
	UFrontendCommonRotator* CommonRotator_AvailableOptions;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess = "true"))
	UFrontendCommonButtonBase* CommonButton_NextOption;
	//***** Bound Widgets ***** //

	UPROPERTY(Transient)
	UListDataObject_String* CachedOwningStringDataObject;


	void OnPreviousOptionButtonClicked();
	void OnNextOptionButtonClicked();
	
	void OnRotatorValueChanged(int32 Value, bool bUserInitiated);
};
