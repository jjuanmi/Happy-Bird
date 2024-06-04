#ifndef BUTTON_H
#define BUTTON_H
#include "Object.h"
#include <string>
using namespace std;

class Button : public Object {
public:
	Button();
	void setTextures(Texture normal,Texture pressed);
	void Update();
	void Select();
	void Unselect();
	bool getStatus();
	void setButtonScale(Vector2f scale);
	void setButtonPosition(Vector2f pos);
	Sprite getSprite();
private:
	bool m_selected = false;
	bool m_canPress = true;
	Texture m_texturePressedButton;
};

#endif

