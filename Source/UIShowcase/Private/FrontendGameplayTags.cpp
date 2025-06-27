// UIShowcase All Rights Reserved.


#include "UIShowcase/Public/FrontendGameplayTags.h"

namespace FrontendGameplayTags
{
	//Frontend widget stack
	UISHOWCASE_API UE_DEFINE_GAMEPLAY_TAG(Frontend_WidgetStack_Modal, "Frontend.WidgetStack.Modal");
	UISHOWCASE_API UE_DEFINE_GAMEPLAY_TAG(Frontend_WidgetStack_GameMenu, "Frontend.WidgetStack.GameMenu");
	UISHOWCASE_API UE_DEFINE_GAMEPLAY_TAG(Frontend_WidgetStack_GameHUD, "Frontend.WidgetStack.GameHUD");
	UISHOWCASE_API UE_DEFINE_GAMEPLAY_TAG(Frontend_WidgetStack_Frontend, "Frontend.WidgetStack.Frontend");

	//Frontend widgets
	UE_DEFINE_GAMEPLAY_TAG(Frontend_Widget_PressAnyKeyScreen,"Frontend.Widget.PressAnyKeyScreen");
	UE_DEFINE_GAMEPLAY_TAG(Frontend_Widget_MainMenuScreen,"Frontend.Widget.MainMenuScreen");
	UE_DEFINE_GAMEPLAY_TAG(Frontend_Widget_OptionScreen,"Frontend.Widget.OptionScreen");
	
	UE_DEFINE_GAMEPLAY_TAG(Frontend_Widget_ConfirmScreen,"Frontend.Widget.ConfirmScreen");
}
