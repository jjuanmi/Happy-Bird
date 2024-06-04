#include "Bird.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;


Bird::Bird():Object("../models/birds/Bird0.png") {
	LoadTexture();
	
	///Sprite
	setBirdSpeed({1,1});
	setBirdPosition({600,360});
	m_sprite.scale(2.5,2.5);
	m_sprite.setOrigin(18,12);
	
	///HitBox
	m_hitBox.setRadius(31);
	m_hitBox.setOrigin(m_hitBox.getRadius(),m_hitBox.getRadius());
	m_hitBox.setFillColor(Color(0,0,0,0));
	m_hitBox.setOutlineColor(Color(255,0,0));
	m_hitBox.setOutlineThickness(2);
	m_hitBox.setPosition(m_pos);
	
	m_wingsSoundBuffer.loadFromFile("../sounds/wings_sound.ogg");
	m_wingsSound.setBuffer(m_wingsSoundBuffer);
	m_wingsSound.setVolume(30);
}

void Bird::Update() {

	
	m_pos.y += m_speed.y;
	
	///para saltar
	if(shouldJump()){
		m_speed.y = 0;
		m_speed.y -= 9.7;
		m_wingsSound.play();
	} else {
		m_speed.y += 0.5;
	}
	

	///evita pasarse del techo
	if(m_pos.y<=0){
		m_speed.y = 0;
		m_pos.y = 0;
		if(shouldJump()){
			m_speed.y -= 9.7;
		} else {
			m_speed.y += 0.5;
		}
	}
	
	m_hitBox.setPosition(m_pos);
	m_sprite.setPosition(m_pos);
	
	Animation();
	if(m_clock.getElapsedTime().asMilliseconds()>1000){m_clock.restart();}
	
	if(m_startHitAnimation){
		if (m_clockHitAnimation.getElapsedTime() < m_timeHitAnimation) {
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 0)
				m_sprite.setColor({255,255,255,120});
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 100)
				m_sprite.setColor({255,255,255,255});
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 200)
				m_sprite.setColor({255,255,255,120});
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 300)
				m_sprite.setColor({255,255,255,255});
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 400)
				m_sprite.setColor({255,255,255,120});
			if(m_clockHitAnimation.getElapsedTime().asMilliseconds() > 500)
				m_sprite.setColor({255,255,255,255});
		}
	} else {
		m_sprite.setColor({255,255,255,255});
		m_startHitAnimation = false;
	}
	
}

bool Bird::shouldJump(){
	if(Keyboard::isKeyPressed(Keyboard::Key::Up) and !m_upKeyPressed){
		m_upKeyPressed = true;
		return true;
	} else{
		if(!Keyboard::isKeyPressed(Keyboard::Key::Up)){
			m_upKeyPressed = false;
		}
	}
	return false;
}

bool Bird::isAlive(){
	return m_isAlive;
}


void Bird::Dead(){
	m_isAlive = false;
}

FloatRect Bird::getHitBox(){
	return m_hitBox.getGlobalBounds();
}

void Bird::Revive(){
	m_isAlive = true;
}

void Bird::setBirdPosition(Vector2f pos){
	m_pos = pos;
	m_sprite.setPosition(m_pos);
}

void Bird::setBirdSpeed(Vector2f speed){
	m_speed = speed;
}

void Bird::Animation(){
	if(m_clock.getElapsedTime().asMilliseconds()>0){m_sprite.setTexture(m_texBirdWingsUp);}
	if(m_clock.getElapsedTime().asMilliseconds()>250){m_sprite.setTexture(m_texture);}
	if(m_clock.getElapsedTime().asMilliseconds()>500){m_sprite.setTexture(m_texBirdWingsDown);}
	if(m_clock.getElapsedTime().asMilliseconds()>750){m_sprite.setTexture(m_texture);}
}

void Bird::LoadTexture(){
	ifstream file("../data.dat",ios::binary|ios::in);
	int aux;
	file.seekg(sizeof(int)*2);
	file.read(reinterpret_cast<char*>(&aux),sizeof(int));
	if(aux<1)aux = 1;
	if(aux>3)aux = 3;
	
	switch(aux){
	case 1:
		m_texture.loadFromFile("../models/birds/Bird0.png");
		m_texBirdWingsUp.loadFromFile("../models/birds/Bird0_wings_up.png");
		m_texBirdWingsDown.loadFromFile("../models/birds/Bird0_wings_Down.png");
		break;
	case 2:
		m_texture.loadFromFile("../models/birds/Bird1.png");
		m_texBirdWingsUp.loadFromFile("../models/birds/Bird1_wings_up.png");
		m_texBirdWingsDown.loadFromFile("../models/birds/Bird1_wings_Down.png");
		break;
	case 3:
		m_texture.loadFromFile("../models/birds/Bird2.png");
		m_texBirdWingsUp.loadFromFile("../models/birds/Bird2_wings_up.png");
		m_texBirdWingsDown.loadFromFile("../models/birds/Bird2_wings_Down.png");
		break;
	}
	file.read(reinterpret_cast<char*>(&aux),sizeof(int));
	file.close();
}

void Bird :: HitAnimation(){
	m_startHitAnimation = true;
	m_clockHitAnimation.restart();
}

Vector2f Bird :: getPosition(){
	return m_sprite.getPosition();
}
