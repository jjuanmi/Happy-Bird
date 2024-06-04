#include "Tubo.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <fstream>
using namespace std;


Tubo::Tubo(): Object("../models/tubos/tubo0.png"){
	LoadTexture();
	setTuboPosition(m_pos);
	m_sprite.scale(7,10);
	
	m_hitBox1.setSize(Vector2f(96,1000));
	m_hitBox1.setFillColor(Color(0,0,0,0));
	m_hitBox1.setOutlineColor(Color(255,0,0));
	m_hitBox1.setOutlineThickness(2);
	m_hitBox1.setPosition(m_pos.x+40,m_pos.y-600);
	
	m_hitBox2.setSize(Vector2f(96,1000));
	m_hitBox2.setFillColor(Color(0,0,0,0));
	m_hitBox2.setOutlineColor(Color(255,0,0));
	m_hitBox2.setOutlineThickness(2);
	m_hitBox2.setPosition(m_pos.x+40,m_pos.y+610);
	
	
	m_hitBox3.setSize(Vector2f(1,1000));
	m_hitBox3.setFillColor(Color(0,0,0,0));
	m_hitBox3.setOutlineColor(Color(0,255,0));
	m_hitBox3.setOutlineThickness(2);
	m_hitBox3.setPosition(m_pos.x+140,m_pos.y);
	
}

void Tubo::Update() {
	m_sprite.move(m_speed);
	m_hitBox1.move(m_speed);
	m_hitBox2.move(m_speed);
	m_hitBox3.move(m_speed);
	
	
	auto m_pos = m_sprite.getPosition();
	if(m_pos.x<=-120){
		Vector2f aux_position = GeneratePosition();
		m_sprite.setPosition(aux_position);
		m_hitBox1.setPosition(aux_position.x+40,aux_position.y-600);
		m_hitBox2.setPosition(aux_position.x+40,aux_position.y+610);
		m_hitBox3.setPosition(aux_position.x+140,aux_position.y);
	}
}

Vector2f Tubo::GeneratePosition(){
	int n=(std::rand()%7)+1;
	switch(n){
	case 1:
		return {1280,-250};
	case 2:
		return {1280,-200};
	case 3:
		return {1280,-150};
	case 4:
		return {1280,-100};
	case 5: 
		return {1280,-50};
	case 6:
		return {1280,0};
	case 7:
		return {1280,-260};
	}
}

FloatRect Tubo::getHitBox1(){
	return m_hitBox1.getGlobalBounds();
}

FloatRect Tubo::getHitBox2(){
	return m_hitBox2.getGlobalBounds();
}

FloatRect Tubo::getHitBox3(){
	return m_hitBox3.getGlobalBounds();
}

void Tubo::AddSpeed(){
	m_speed.x -= 1;
}

void Tubo::setTuboPosition(Vector2f pos){
	m_pos = pos;
	m_sprite.setPosition(pos);
	m_hitBox1.setPosition(pos.x+40,pos.y-600);
	m_hitBox2.setPosition(pos.x+40,pos.y+610);
	m_hitBox3.setPosition(pos.x+140,pos.y);
	m_sprite.setPosition(m_pos);
}

void Tubo::setTuboSpeed(Vector2f speed){
	m_speed = speed;
}

void Tubo::LoadTexture(){
	ifstream file("../data.dat",ios::binary|ios::in);
	file.seekg(sizeof(int)*3);
	int aux;
	file.read(reinterpret_cast<char*>(&aux),sizeof(int));
	file.close();
	if(aux<1)aux = 1;
	if(aux>3)aux = 3;
	
	switch(aux){
	case 1:
		m_texture.loadFromFile("../models/tubos/tubo0.png");
		break;
	case 2:
		m_texture.loadFromFile("../models/tubos/tubo1.png");
		break;
	case 3:
		m_texture.loadFromFile("../models/tubos/tubo2.png");
		break;
	}
}

Vector2f Tubo :: getPosition(){
	return m_sprite.getPosition();
}
