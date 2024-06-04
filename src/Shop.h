#ifndef SHOP_H
#define SHOP_H
#include "Scene.h"
#include "Button.h"
#include "Cloud.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;

class Shop : public Scene{
public:
	Shop();
	void Update (Game & game)override;
	void Draw (RenderWindow & window)override;
	void setDefaults();
	void UpdateSelected();
	bool CanSelect();
private:
	
	Font m_font;
	Text m_textBack;
	Text m_textPoints;
	Text m_text200points;
	Text m_text300points;
	Text m_text500points;
	Text m_text600points;
	
	
	int m_totalPoints;
	int m_bestScore;
	int m_skinBird;
	int m_skinTubo;
	int m_buttonSelected;
	
	bool m_keyStatus = true;
	bool m_spaceStatus = true;
	
	Texture m_texMenu;
	Texture m_texBird0;
	Texture m_texBird1;
	Texture m_texBird2;
	Texture m_texTubo0;
	Texture m_texTubo1;
	Texture m_texTubo2;
	Texture m_texLock;
	Texture m_texSelected;
	
	Sprite m_spriteMenu;
	Sprite m_spriteBird0;
	Sprite m_spriteBird1;
	Sprite m_spriteBird2;
	Sprite m_spriteTubo0;
	Sprite m_spriteTubo1;
	Sprite m_spriteTubo2;
	Sprite m_spriteLock0;
	Sprite m_spriteLock1;
	Sprite m_spriteLock2;
	Sprite m_spriteLock3;
	Sprite m_spriteSelected0;
	Sprite m_spriteSelected1;
	
	SoundBuffer m_clickSoundBuffer;
	SoundBuffer m_selectedSoundBuffer;
	SoundBuffer m_errorSoundBuffer;
	
	Sound m_clickSound;
	Sound m_selectedSound;
	Sound m_errorSound;
	
	vector<Button>m_buttons;
	
	Cloud m_cloud1;
	Cloud m_cloud2;
	Cloud m_cloud3;
	Cloud m_cloud4;
};

#endif

