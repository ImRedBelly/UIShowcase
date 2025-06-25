// UIShowcase All Rights Reserved.


#include "Subsystems/FrontendUISubsystem.h"

#include "FrontendFunctionLibrary.h"
#include "FrontendGameplayTags.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Engine/AssetManager.h"
#include "Widgets/Widget_ConfirmScreen.h"
#include "Widgets/Widget_PrimaryLayout.h"

UFrontendUISubsystem* UFrontendUISubsystem::Get(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);

		return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
	}

	return nullptr;
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
	{
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(), FoundClasses);

		return FoundClasses.IsEmpty();
	}

	return false;
}

void UFrontendUISubsystem::RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget)
{
	check(InCreatedWidget);
	CreatedPrimaryLayout = InCreatedWidget;
}

void UFrontendUISubsystem::PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag,
                                                      TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,
                                                      TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)>
                                                      AsyncPushStateCallback)
{
	check(!InSoftWidgetClass.IsNull());

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InSoftWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[InSoftWidgetClass, this, InWidgetStackTag, AsyncPushStateCallback]()
			{
				UClass* LoadedWidgetClass = InSoftWidgetClass.Get();
				check(LoadedWidgetClass && CreatedPrimaryLayout)

				UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(
					InWidgetStackTag);

				UWidget_ActivatableBase* CreatedWidget = FoundWidgetStack->AddWidget<UWidget_ActivatableBase>(
					LoadedWidgetClass, [AsyncPushStateCallback](UWidget_ActivatableBase& CreatedWidgetInstance)
					{
						AsyncPushStateCallback(EAsyncPushWidgetState::OnCreateBeforePush, &CreatedWidgetInstance);
					});
				AsyncPushStateCallback(EAsyncPushWidgetState::AfterPush, CreatedWidget);
			})
	);
}

void UFrontendUISubsystem::PushConfirmScreenToModalStackAsync(EConfirmScreenType InScreenType,
                                                              const FText& InScreenTitle, const FText& InScreenMsg,
                                                              TFunction<void(EConfirmScreenButtonType)>
                                                              ButtonClickedCallback)
{
	UConfirmScreenInfoObject* CreatedInfoObject = nullptr;

	switch (InScreenType)
	{
	case EConfirmScreenType::Ok:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateOkScreen(InScreenTitle, InScreenMsg);
		break;
	case EConfirmScreenType::YesNo:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateYesNoScreen(InScreenTitle, InScreenMsg);
		break;
	case EConfirmScreenType::OkCancel:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateOkCancelScreen(InScreenTitle, InScreenMsg);
		break;
	case EConfirmScreenType::Unknown:
		break;
	}

	check(CreatedInfoObject);

	PushSoftWidgetToStackAsync(FrontendGameplayTags::Frontend_WidgetStack_Modal,
	                           UFrontendFunctionLibrary::GetFrontendSoftWidgetClassByTag(
		                           FrontendGameplayTags::Frontend_Widget_ConfirmScreen),
	                           [CreatedInfoObject, ButtonClickedCallback](
	                           EAsyncPushWidgetState InPushState, UWidget_ActivatableBase* PushedWidget)
	                           {
		                           if (InPushState == EAsyncPushWidgetState::OnCreateBeforePush)
		                           {
			                           UWidget_ConfirmScreen* CreatedConfirmScreen = CastChecked<UWidget_ConfirmScreen>(
				                           PushedWidget);
			                           CreatedConfirmScreen->
				                           InitConfirmScreen(CreatedInfoObject, ButtonClickedCallback);
		                           }
	                           }
	);
}
