#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <vector>

#define VOLUME 100
#define MUSIC_VOLUME 70
#define MAX_CHANNELS 25

enum class MusicAudio {
	Background = 0
};

enum class SFXAudio {
	UISuccess = 0,
	UIFail,
	MenuSuccess,
	MenuFail,
	EnemyHit,
	EnemyDeath,
	EnemyFire,
	PlayerDeath,
	PlayerFire1,
	PlayerFire2
};


class AudioManager {
public:
	static AudioManager* Instance();
	static void Release();

	void PlayMusic(MusicAudio name, int loops = -1);
	void PauseMusic();
	void ResumeMusic();
	void StopMusic();

	void PlaySFX(SFXAudio name, int loops = 0, int channel = -1);

private:
	static AudioManager* instance;

	AudioManager();
	~AudioManager();

	void AudioInit();

	std::vector<std::pair<MusicAudio, Mix_Music*>> music;
	std::vector<std::pair<SFXAudio, Mix_Chunk*>> sfx;
};

