// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontendTypes/FrontendEnumTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "FrontendUISubsystem.generated.h"

class UFrontendCommonButtonBase;
class UWidget_ActivatableBase;
struct FGameplayTag;
class UWidget_PrimaryLayout;

enum class EAsyncPushWidgetState
{
	OnCreateBeforePush,
	AfterPush,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonDescriptionTextUpdatedDelegate, UFrontendCommonButtonBase*,
                                             BroadcastingButton, FText, DescriptionText);

/**
 * 
 */
UCLASS()
class UISHOWCASE_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static UFrontendUISubsystem* Get(const UObject* WorldContextObject);

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	UFUNCTION(BlueprintCallable)
	void RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget);

	void PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag,
	                                TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,
	                                TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)>
	                                AsyncPushStateCallback);

	void PushConfirmScreenToModalStackAsync(EConfirmScreenType InScreenType,
	                                        const FText& InScreenTitle, const FText& InScreenMsg,
	                                        TFunction<void(EConfirmScreenButtonType)> ButtonClickedCallback);

	UPROPERTY(BlueprintAssignable)
	FOnButtonDescriptionTextUpdatedDelegate OnButtonDescriptionTextUpdated;

private:
	UPROPERTY(Transient)
	UWidget_PrimaryLayout* CreatedPrimaryLayout;
};
