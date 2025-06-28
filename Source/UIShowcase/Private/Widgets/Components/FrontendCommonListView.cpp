// UIShowcase All Rights Reserved.

#include "Widgets/Components/FrontendCommonListView.h"

#include "Editor/WidgetCompilerLog.h"
#include "Widgets/Options/DataAsset_DataListEntryMapping.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"

UUserWidget& UFrontendCommonListView::OnGenerateEntryWidgetInternal(UObject* Item,
                                                                    TSubclassOf<UUserWidget> DesiredEntryClass,
                                                                    const TSharedRef<STableViewBase>& OwnerTable)
{
	if (IsDesignTime())
	{
		return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
	}

	if(TSubclassOf<UWidget_ListEntry_Base> FoundWidgetClass = DataListEntryMapping->FindEntryWidgetClassByDataObject(CastChecked<UListDataObject_Base>(Item)))
	{
		return GenerateTypedEntry<UWidget_ListEntry_Base>(FoundWidgetClass, OwnerTable);
	}
	
	return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
}

#if WITH_EDITOR
void UFrontendCommonListView::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!DataListEntryMapping)
	{
		CompileLog.Error(FText::FromString(
			TEXT("The variable DataListEntryMapping has no valid data asset assigned ") +
			GetClass()->GetName() +
			TEXT(" needs a valid data asset to function properly")));
	}
}
#endif
