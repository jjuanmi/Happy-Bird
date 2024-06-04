#ifndef CLOUD_H
#define CLOUD_H
#include "Object.h"
#include <SFML/System/Vector2.hpp>
#include <string>
using namespace std;

class Cloud : public Object {
public:
	Cloud();
	void Update();
	string setRandTexture();
	Vector2f GeneratePosition();
	void setCloudPosition(Vector2f pos);
	void setSpeed(Vector2f speed);
	Vector2f getPosition();
	Sprite getSprite();
	Vector2f getSpeed();
	void setTexture(string texture);
private:
	Vector2f m_position = {1280,0};
	Vector2f m_speed = {-3,0};
};

#endif

