#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Button.h"
#include "Cloud.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

using namespace sf;

class Menu : public Scene{
public:
	Menu();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void setDefaults();	
private:
	Text m_textTitle;
	Text m_textTitle1;
	Font m_fontTitle;
	Button m_buttonPlay;
	Button m_buttonShop;
	
	Cloud m_cloud1;
	Cloud m_cloud2;
	Cloud m_cloud3;
	
	Texture m_texButtonPlay;
	Texture m_texButtonPlayP;
	Texture m_texButtonShop;
	Texture m_texButtonShopP;
	
	SoundBuffer m_clickSoundBuffer;
	Sound m_clickSound;
	
	SoundBuffer m_selectedSoundBuffer;
	Sound m_selectedSound;
	
	SoundBuffer m_musicSoundBuffer;
	Sound m_musicSound;
	
	bool m_keyStatus = false;
};

#endif

