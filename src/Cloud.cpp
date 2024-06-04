#include "Cloud.h"
#include <iostream>
using namespace std;



Cloud::Cloud() : Object(setRandTexture()) {

}

void Cloud::Update(){
	m_sprite.move(m_speed);
	if(m_sprite.getPosition().x <= -190){
		m_sprite.setPosition(GeneratePosition());
	}
}

string Cloud::setRandTexture(){
	int n = (rand()%6)+1;
	switch(n){
	case 1:
		return "../models/clouds/cloud1.png";
	case 2:
		return "../models/clouds/cloud2.png";
	case 3:
		return "../models/clouds/cloud3.png";
	case 4:
		return "../models/clouds/cloud4.png";
	case 5:
		return "../models/clouds/cloud5.png";
	case 6:
		return "../models/clouds/cloud6.png";
	}
}

Vector2f Cloud::GeneratePosition(){
	int n = (rand()%500);
	Vector2f pos;
	pos.x = 1320;
	pos.y = n;
	return pos;
}

void Cloud::setCloudPosition(Vector2f pos){
	m_sprite.setPosition(pos);
}

Sprite Cloud::getSprite(){
	return m_sprite;
}

void Cloud::setSpeed(Vector2f speed){
	m_speed = speed;
}

Vector2f Cloud::getSpeed(){
	return m_speed;
}

void Cloud::setTexture(string texture){
	m_texture.loadFromFile(texture);
	m_sprite.setTexture(m_texture);
}

