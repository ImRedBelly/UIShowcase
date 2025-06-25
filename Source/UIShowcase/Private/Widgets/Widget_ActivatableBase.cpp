// UIShowcase All Rights Reserved.


#include "Widgets/Widget_ActivatableBase.h"

#include "Controllers/FrontendPlayerController.h"

AFrontendPlayerController* UWidget_ActivatableBase::GetOwningFrontendPlayerController()
{
	if (!CachedOwningFrontendPC.IsValid())
	{
		CachedOwningFrontendPC = GetOwningPlayer<AFrontendPlayerController>();
	}
	return CachedOwningFrontendPC.IsValid() ? CachedOwningFrontendPC.Get() : nullptr;
}
