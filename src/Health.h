#ifndef HEALTH_H
#define HEALTH_H
#include "Object.h"

class Health : public Object {
public:
	Health();
	void Update();
	void setPosition(Vector2f pos);
	void setStatus(bool status);
	bool getStatus();
	void setScale(Vector2f scale);
	Sprite getSprite();
private:
	Texture m_texHealth0;
	bool m_status =  true;
	Vector2f m_pos = {0,0};
};

#endif

