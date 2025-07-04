// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Value.h"
#include "ListDataObject_String.generated.h"

/**
 * 
 */
UCLASS()
class UISHOWCASE_API UListDataObject_String : public UListDataObject_Value
{
	GENERATED_BODY()

public:
	void AddDynamicOption(const FString& InStringValue, const FText& InDisplayText);
	void AdvanceToNextOption();
	void BackToPreviousOption();
	void OnRotatorInitiatedValueChanged(const FText& InNewSelectedText);

protected:
	FString CurrentStringValue;
	FText CurrentDisplayText;

	TArray<FString> AvailableOptionsStringArray;
	TArray<FText> AvailableOptionsTextArray;

	//~ Begin UListDataObject_Base Interface
	virtual void OnDataObjectInitialized() override;
	virtual bool CanResetBackToDefaultValue() const override;
	virtual bool TryResetBackToDefaultValue() override;
	virtual bool CanSetToForcedStringValue(const FString& InForcedValue) const override;
	virtual void OnSetToForcedStringValue(const FString& InForcedValue) override;
	//~ Begin UListDataObject_Base Interface

	bool TrySetDisplayTextFromStringValue(const FString& InStringValue);

public:
	FORCEINLINE const TArray<FText>& GetAvailableOptionsTextArray() const { return AvailableOptionsTextArray; };
	FORCEINLINE FText GetCurrentDisplayText() const { return CurrentDisplayText; };
};

UCLASS()
class UISHOWCASE_API UListDataObject_StringBool : public UListDataObject_String
{
	GENERATED_BODY()

public:
	void OverrideTrueDisplayText(const FText& InNewTrueDisplayText);
	void OverrideFalseDisplayText(const FText& InNewFalseDisplayText);

	void SetTrueAsDefaultValue();
	void SetFalseAsDefaultValue();

protected:
	//~ Begin UListDataObject_String Interface
	virtual void OnDataObjectInitialized() override;
	//~ Begin UListDataObject_String Interface
private:
	void TryInitBoolValues();

	const FString TrueString = TEXT("true");
	const FString FalseString = TEXT("false");
};

UCLASS()
class UISHOWCASE_API UListDataObject_StringEnum : public UListDataObject_String
{
	GENERATED_BODY()

public:
	template <typename EnumType>
	void AddEnumOption(EnumType InEnumOption, const FText& InDisplayText)
	{
		const UEnum* StaticEnumOption = StaticEnum<EnumType>();
		const FString ConvertedEnumString = StaticEnumOption->GetNameStringByValue(InEnumOption);

		AddDynamicOption(ConvertedEnumString, InDisplayText);
	}

	template <typename EnumType>
	EnumType GetCurrentValueAsEnum() const
	{
		const UEnum* StaticEnumOption = StaticEnum<EnumType>();
		return (EnumType)StaticEnumOption->GetValueByNameString(CurrentStringValue);
	}

	template <typename EnumType>
	void SetDefaultValueFromEnumOption(EnumType InEnumOption)
	{
		const UEnum* StaticEnumOption = StaticEnum<EnumType>();
		const FString ConvertedEnumString = StaticEnumOption->GetNameStringByValue(InEnumOption);

		SetDefaultValueFromString(ConvertedEnumString);
	}
};

UCLASS()
class UISHOWCASE_API UListDataObject_StringInteger : public UListDataObject_String
{
	GENERATED_BODY()

public:
	void AddIntegerOption(int32 InIntegerValue, const FText& InDisplayText);

protected:
	
	//~ Begin UListDataObject_String Interface
	virtual void OnDataObjectInitialized() override;
	virtual void OnEditDependencyDataModified(UListDataObject_Base* ModifiedDependencyData,
	                                          EOptionsListDataModifyReason ModifyReason) override;
	//~ End UListDataObject_String Interface
};
