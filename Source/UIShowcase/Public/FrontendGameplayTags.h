// UIShowcase All Rights Reserved.

#pragma once

#include "NativeGameplayTags.h"

namespace FrontendGameplayTags
{
	//Frontend widget stack
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_Modal)
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_GameMenu)
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_GameHUD)
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_Frontend)

	//Frontend widgets
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_PressAnyKeyScreen);
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_MainMenuScreen);
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_OptionScreen);

	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_ConfirmScreen);
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_KeyRemapScreen);

	//Frontend Options Image
	UISHOWCASE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Image_TestImage);
}
