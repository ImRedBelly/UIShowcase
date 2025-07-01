// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PropertyPathHelpers.h"

class UFrontendGameUserSettings;
/**
 * 
 */
class UISHOWCASE_API FOptionsDataInteractionHelper
{
public:
	FOptionsDataInteractionHelper(const FString& InSetterOrGetterFuncPath);

	FString GetValueAsString() const;
	void SetValueFromString(const FString& InStringValue) const;

private:
	FCachedPropertyPath CachedDynamicFunctionPath;

	TWeakObjectPtr<UFrontendGameUserSettings> CachedWeakGameUserSettings;
};
