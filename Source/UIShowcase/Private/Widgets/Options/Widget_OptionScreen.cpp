// UIShowcase All Rights Reserved.


#include "Widgets/Options/Widget_OptionScreen.h"

#include "FrontendDebugHelper.h"
#include "Input/CommonUIInputTypes.h"
#include "ICommonInputModule.h"
#include "Widgets/Components/FrontendTabListWidgetBase.h"
#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"

void UWidget_OptionScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!ResetAction.IsNull())
	{
		ResetActionHandle = RegisterUIActionBinding(
			FBindUIActionArgs(
				ResetAction,
				true,
				FSimpleDelegate::CreateUObject(this, &UWidget_OptionScreen::OnResetBoundActionTriggered)
			)
		);
	}

	RegisterUIActionBinding(
		FBindUIActionArgs(
			ICommonInputModule::GetSettings().GetDefaultBackAction(),
			true,
			FSimpleDelegate::CreateUObject(this, &UWidget_OptionScreen::OnBackBoundActionTriggered)
		)
	);

	TabListWidget_OptionsTabs->OnTabSelected.AddUniqueDynamic(this, &ThisClass::OnOptionsTabSelected);
}

void UWidget_OptionScreen::NativeOnActivated()
{
	Super::NativeOnActivated();

	for (const auto TabCollection : GetOrCreateDataRegistry()->GetRegisteredOptionsTabCollections())
	{
		if (!TabCollection)
		{
			continue;
		}

		const auto TabID = TabCollection->GetDataID();
		if (TabListWidget_OptionsTabs->GetTabButtonBaseByID(TabID) != nullptr)
		{
			continue;
		}
		TabListWidget_OptionsTabs->RequestRegisterTab(TabID, TabCollection->GetDataDisplayName());
	}
}

UOptionsDataRegistry* UWidget_OptionScreen::GetOrCreateDataRegistry()
{
	if (!CreatedOwningDataRegistry)
	{
		CreatedOwningDataRegistry = NewObject<UOptionsDataRegistry>();
		CreatedOwningDataRegistry->InitOptionsDataRegistry(GetOwningLocalPlayer());
	}
	checkf(CreatedOwningDataRegistry, TEXT("Data registry for options screen is not valid"));
	return CreatedOwningDataRegistry;
}

void UWidget_OptionScreen::OnResetBoundActionTriggered()
{
	Debug::Print(TEXT("Reset bound action triggered"));
}

void UWidget_OptionScreen::OnBackBoundActionTriggered()
{
	DeactivateWidget();
}

void UWidget_OptionScreen::OnOptionsTabSelected(FName TabId)
{
	Debug::Print(TEXT("New Tab Selected. Tab ID: ") + TabId.ToString());
}
