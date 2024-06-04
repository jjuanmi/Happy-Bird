#include "AdditionalHealth.h"

AdditionalHealth::AdditionalHealth() : Object("../models/buttons/health1.png") {
	m_healthTexture2.loadFromFile("../models/buttons/health2.png");
	m_healthTexture3.loadFromFile("../models/buttons/health3.png");
	m_healthTexture4.loadFromFile("../models/buttons/health4.png");
	m_healthTexture5.loadFromFile("../models/buttons/health5.png");
	m_healthTexture6.loadFromFile("../models/buttons/health6.png");
	m_healthTexture7.loadFromFile("../models/buttons/health7.png");
	
}

void AdditionalHealth :: setPosition(Vector2f pos){
	m_sprite.setPosition(pos);
}
void AdditionalHealth :: setScale(Vector2f scale){
	m_sprite.setScale(scale);
}
Sprite AdditionalHealth :: getSprite(){
	return m_sprite;
}


void AdditionalHealth :: Update(){
	m_sprite.move(m_speed);
	
	auto m_pos = m_sprite.getPosition();
	
	Animation();
	if(m_clock.getElapsedTime().asMilliseconds()>600){
		m_clock.restart();
	}
}

void AdditionalHealth :: Animation(){
	if(m_clock.getElapsedTime().asMilliseconds()>0){m_sprite.setTexture(m_healthTexture2);}
	if(m_clock.getElapsedTime().asMilliseconds()>100){m_sprite.setTexture(m_healthTexture3);}
	if(m_clock.getElapsedTime().asMilliseconds()>200){m_sprite.setTexture(m_healthTexture4);}
	if(m_clock.getElapsedTime().asMilliseconds()>300){m_sprite.setTexture(m_healthTexture5);}
	if(m_clock.getElapsedTime().asMilliseconds()>400){m_sprite.setTexture(m_healthTexture6);}
	if(m_clock.getElapsedTime().asMilliseconds()>500){m_sprite.setTexture(m_healthTexture7);}
}

Vector2f AdditionalHealth ::GeneratePosition(){
	Vector2f position;
	position.x = 1280;
	position.y = rand()%700;
	return position;
}

void AdditionalHealth :: setSpeed(Vector2f speed){
	m_speed = speed;
}

void AdditionalHealth :: AddSpeed(){
	m_speed.x -= 1;
}
