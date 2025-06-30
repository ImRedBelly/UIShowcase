// UIShowcase All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontendDebugHelper.h"
#include "GameFramework/GameUserSettings.h"
#include "FrontendGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class UISHOWCASE_API UFrontendGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFrontendGameUserSettings();
	static UFrontendGameUserSettings* Get();

	//***** Gameplay Collections Tab *****//
	UFUNCTION()
	FString GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }

	UFUNCTION()
	void SetCurrentGameDifficulty(const FString& InNewDifficulty) { CurrentGameDifficulty = InNewDifficulty; }

	//***** Gameplay Collections Tab *****//


	//***** Audio Collections Tab *****//
	UFUNCTION()
	float GetCurrentOverallVolume() const { return CurrentOverallVolume; }

	UFUNCTION()
	void SetCurrentOverallVolume(float InNewOverallVolume);

	UFUNCTION()
	float GetCurrentMusicVolume() const { return CurrentMusicVolume; }

	UFUNCTION()
	void SetCurrentMusicVolume(float InNewCurrentMusicVolume);

	UFUNCTION()
	float GetCurrentSoundFXVolume() const { return CurrentSoundFXVolume; }

	UFUNCTION()
	void SetCurrentSoundFXVolume(float InNewCurrentSoundFXVolume);

	UFUNCTION()
	bool GetAllowBackgroundAudio() const { return bAllowBackgroundAudio; }

	UFUNCTION()
	void SetAllowBackgroundAudio(bool InNewAllowBackgroundAudio);
	
	UFUNCTION()
	bool GetUseHDRAudioMode() const { return bUseHDRAudioMode; }

	UFUNCTION()
	void SetUseHDRAudioMode(bool InNewUseHDRAudioMode);
	//***** Audio Collections Tab *****//

private:
	//***** Gameplay Collections Tab *****//
	UPROPERTY(Config)
	FString CurrentGameDifficulty;
	//***** Gameplay Collections Tab *****//

	//***** Audio Collections Tab *****//
	UPROPERTY(Config)
	float CurrentOverallVolume = 2.f;

	UPROPERTY(Config)
	float CurrentMusicVolume = 2.f;

	UPROPERTY(Config)
	float CurrentSoundFXVolume = 2.f;

	UPROPERTY(Config)
	bool bAllowBackgroundAudio;

	UPROPERTY(Config)
	bool bUseHDRAudioMode;
	//***** Audio Collections Tab *****//
};
