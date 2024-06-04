#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Bird.h"
#include "Tubo.h"
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Cloud.h"
#include "Button.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Health.h"
#include "AdditionalHealth.h"

using namespace sf;

class Match : public Scene {
public:
	
	Match();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void DetectCollision();
	void AddPoint();
	void setDefaults();
	void GameOverScreen();
	void PlayAgain();
	void ResetShouldAddPoint();
	void SpawnAdditionalHealth();
	void AddHealth();
	
private:
	
	Bird m_bird;
	Tubo m_tubo;
	int m_points = 0;
	int m_totalPoints;
	int m_bestScore;
	int m_skinBird;
	int m_skinTubo;
	
	
	Text m_textPoints;
	Font m_font1;
	Font m_font2;
	bool m_shouldAddSpeed = false;
	bool m_pointAdded = false;
	
	Cloud m_cloud1;	
	Cloud m_cloud2;
	Cloud m_cloud3;
	
	Texture m_menuTexture;
	Texture m_texButtonPlay;
	Texture m_texButtonPlayP;
	Texture m_texButtonMenu;
	Texture m_texButtonMenuP;
	
	
	Sprite m_gameOverMenu;
	
	Text m_textGameOver;
	Text m_textTotalPoints;
	Text m_textBest;
	
	Button m_buttonPlay;
	Button m_buttonMenu;
	
	bool m_showGameOverScreen;
	bool m_spaceKeyPressed = false;
	bool m_keyStatus = false;
	bool m_collisionDetected = false;
	bool m_shouldAddPoint = true;
	bool m_healthAdded = false;
	
	SoundBuffer m_coinSoundBuffer;
	Sound m_coinSound;
	
	SoundBuffer m_deadSoundBuffer;
	Sound m_deadSound;
	
	SoundBuffer m_clickSoundBuffer;
	Sound m_clickSound;
	
	SoundBuffer m_selectedSoundBuffer;
	Sound m_selectedSound;
	
	SoundBuffer m_hitSoundBuffer;
	Sound m_hitSound;
	
	Health m_h1;
	Health m_h2;
	Health m_h3;
	AdditionalHealth m_additionalHealth;
};

#endif

