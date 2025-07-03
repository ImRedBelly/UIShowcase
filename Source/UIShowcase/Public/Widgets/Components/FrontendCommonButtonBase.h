// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FrontendCommonButtonBase.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UISHOWCASE_API UFrontendCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	void SetButtonText(FText InText);

	UFUNCTION(BlueprintCallable)
	FText GetButtonDisplayText() const;

	UFUNCTION(BlueprintCallable)
	void SetButtonDisplayImage(const FSlateBrush& InBrush);

private:
	virtual void NativePreConstruct() override;
	virtual void NativeOnCurrentTextStyleChanged() override;
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;

	UPROPERTY(meta=(BindWidgetOptional))
	UCommonTextBlock* CommonTextBlock_ButtonText;
	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional, AllowPrivateAccess = "true"))
	UCommonLazyImage* CommonLazyImage_ButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Button", meta=(AllowPrivateAccess = "true"))
	FText ButtonDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Button", meta=(AllowPrivateAccess = "true"))
	bool bUseUpperCaseForButtonText = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Button", meta=(AllowPrivateAccess = "true"))
	FText ButtonDescriptionText;
};
