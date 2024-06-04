#ifndef TUBO_H
#define TUBO_H
#include "Object.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Tubo : public Object {
public:
	Tubo();
	void Update();
	Vector2f GeneratePosition();
	void setTuboSpeed(Vector2f speed);
	
	FloatRect getHitBox1(); ///hitbox tubo de arriba
	FloatRect getHitBox2(); ///hitbox tubo de abajo
	FloatRect getHitBox3(); ///linea final del tubo
	
	void AddSpeed();
	void setTuboPosition(Vector2f pos);
	
	void LoadTexture();
	
	Vector2f getPosition();
private:
	Vector2f m_speed;
	Vector2f m_pos = GeneratePosition();
	RectangleShape m_hitBox1;
	RectangleShape m_hitBox2;
	RectangleShape m_hitBox3;
	
};

#endif

