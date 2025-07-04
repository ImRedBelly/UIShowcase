// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FrontendLoadingScreenInterrface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, MinimalAPI)
class UFrontendLoadingScreenInterrface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UISHOWCASE_API IFrontendLoadingScreenInterrface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void OnLoadingScreenActivated();
	/*virtual void OnLoadingScreenActivated_Implementation();*/

	UFUNCTION(BlueprintNativeEvent)
	void OnLoadingScreenDeactivated();
	/*virtual void OnLoadingScreenDeactivated_Implementation();*/
};
