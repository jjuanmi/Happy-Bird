#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Instructions : public Scene {
public:
	Instructions();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void setDefaults();	
private:
	Clock m_clock;
	Text m_textTitle;
	Text m_textMenu;
	Text m_textGame;
	Text m_textKeys;
	Text m_textKeyUp;
	Text m_textKeySpace;
	
	
	Font m_fontTitle;
	Font m_font;

	Texture m_texKeys;
	Texture m_texKeyUp;
	Texture m_texKeySpace;
	
	Sprite m_sprKeys;
	Sprite m_sprKeyUp;
	Sprite m_sprKeySpace;
	
	RectangleShape m_black;
	float m_aux = 255;
	bool m_SpaceSelected = false;
};

#endif

