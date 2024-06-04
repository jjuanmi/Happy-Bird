#ifndef BIRD_H
#define BIRD_H
#include "Object.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>
#include "Health.h"
using namespace std;


class Bird : public Object {
public:
	Bird();
	void Update();
	bool shouldJump();
	bool isAlive();
	void Dead();
	FloatRect getHitBox();
	Vector2f getPosition();
	void Revive();
	void setBirdPosition(Vector2f pos);
	void setBirdSpeed(Vector2f speed);
	void Animation();
	void HitAnimation();
	void LoadTexture();
	
private:
	Vector2f m_speed = {1,1};
	Vector2f m_pos = {600,360};
	CircleShape m_hitBox;
	bool m_isAlive = true;
	bool m_upKeyPressed = false;
	bool m_startHitAnimation = false;
	
	Texture m_texBirdWingsUp;
	Texture m_texBirdWingsDown;
	
	Sprite m_spriteBirdWingsUp;
	Sprite m_spriteBirdWingsDown;
	
	Clock m_clock;
	Clock m_clockHitAnimation;
	
	Time m_timeHitAnimation = seconds(2.0f);
	
	SoundBuffer m_wingsSoundBuffer;
	Sound m_wingsSound;
	
};

#endif

