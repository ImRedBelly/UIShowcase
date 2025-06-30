// UIShowcase All Rights Reserved.


#include "FrontendSettings/FrontendGameUserSettings.h"

UFrontendGameUserSettings::UFrontendGameUserSettings()
	: CurrentOverallVolume(2.f)
	  , CurrentMusicVolume(2.f)
	  , CurrentSoundFXVolume(2.f)
	  , bAllowBackgroundAudio(false)
	  , bUseHDRAudioMode(false)
{
}

UFrontendGameUserSettings* UFrontendGameUserSettings::Get()
{
	if (GEngine)
	{
		return CastChecked<UFrontendGameUserSettings>(GEngine->GetGameUserSettings());
	}
	return nullptr;
}

void UFrontendGameUserSettings::SetCurrentOverallVolume(float InVolume)
{
	CurrentOverallVolume = InVolume;
}

void UFrontendGameUserSettings::SetCurrentMusicVolume(float InNewCurrentMusicVolume)
{
	CurrentMusicVolume = InNewCurrentMusicVolume;
}

void UFrontendGameUserSettings::SetCurrentSoundFXVolume(float InNewCurrentSoundFXVolume)
{
	CurrentSoundFXVolume = InNewCurrentSoundFXVolume;
}

void UFrontendGameUserSettings::SetAllowBackgroundAudio(bool InNewAllowBackgroundAudio)
{
	bAllowBackgroundAudio = InNewAllowBackgroundAudio;
}
void UFrontendGameUserSettings::SetUseHDRAudioMode(bool InNewUseHDRAudioMode)
{
	bUseHDRAudioMode = InNewUseHDRAudioMode;
}
