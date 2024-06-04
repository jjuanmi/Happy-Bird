#ifndef ADDITIONALHEALTH_H
#define ADDITIONALHEALTH_H
#include "Object.h"

class AdditionalHealth : public Object {
public:
	AdditionalHealth();
	void setPosition(Vector2f pos);
	void setScale(Vector2f scale);
	Sprite getSprite();
	void Update();
	void Animation();
	void setSpeed(Vector2f speed);
	Vector2f GeneratePosition();
	void AddSpeed();
private:
	Texture m_healthTexture2;
	Texture m_healthTexture3;
	Texture m_healthTexture4;
	Texture m_healthTexture5;
	Texture m_healthTexture6;
	Texture m_healthTexture7;
	
	Clock m_clock;
	
	Vector2f m_speed;
};

#endif

