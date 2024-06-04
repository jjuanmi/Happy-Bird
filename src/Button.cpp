#include "Button.h"

Button::Button():Object("../models/Buttons/button.png") {
	m_texturePressedButton.loadFromFile("../models/Buttons/button_pressed.png"); 
}

void Button::Update(){
	
	if(m_selected and m_canPress){
		m_sprite.setTexture(m_texturePressedButton);
		m_canPress = false;
	}
	
	if(!m_selected){
		m_sprite.setTexture(m_texture);
		m_canPress = true;
	}
}


Sprite Button::getSprite(){
	return m_sprite;
}

void Button::setButtonScale(Vector2f scale){
	m_sprite.scale(scale);
}

void Button::setButtonPosition(Vector2f pos){
	m_sprite.setPosition(pos);
}

void Button::Select(){
	m_selected = true;
}

void Button::Unselect(){
	m_selected = false;
}

bool Button::getStatus(){
	return m_selected;
}
void Button::setTextures(Texture normal,Texture pressed){
	m_texture =  normal;
	m_texturePressedButton = pressed;
}
