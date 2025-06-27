// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ListDataObject_Base.generated.h"

#define LIST_DATA_ACCESSOR(DataType,PropertyName) \
	FORCEINLINE DataType Get##PropertyName() const { return PropertyName;} \
	void Set##PropertyName(DataType In##PropertyName) { PropertyName = In##PropertyName;}

/**
 * 
 */
UCLASS()
class UISHOWCASE_API UListDataObject_Base : public UObject
{
	GENERATED_BODY()

public:
	LIST_DATA_ACCESSOR(FName, DataID);
	LIST_DATA_ACCESSOR(FText, DataDisplayName);
	LIST_DATA_ACCESSOR(FText, DescriptionRichText);
	LIST_DATA_ACCESSOR(FText, DisableRichText);
	LIST_DATA_ACCESSOR(TSoftObjectPtr<UTexture2D>, SoftDescriptionImage);
	LIST_DATA_ACCESSOR(UListDataObject_Base*, ParentData);

	void InitDataObject();

	//Empty in the base class. Child class ListDataObject_Collection should override it. The function should return all the child data a tab hasAdd commentMore actions
	virtual TArray<UListDataObject_Base*> GetAllChildListData() const { return TArray<UListDataObject_Base*>(); }
	virtual bool HasAnyChildListData() const { return false; }

protected:
	//Empty in base class. The child classes should override it to handle the initialization needed accrodinglyAdd commentMore actions
	virtual void OnDataObjectInitialized();

private:
	FName DataID;
	FText DataDisplayName;
	FText DescriptionRichText;
	FText DisableRichText;

	TSoftObjectPtr<UTexture2D> SoftDescriptionImage;

	UPROPERTY(Transient)
	UListDataObject_Base* ParentData;
};
