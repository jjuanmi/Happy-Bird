#include "Health.h"

Health :: Health():Object("../models/buttons/health1.png"){
	
	m_texHealth0.loadFromFile("../models/buttons/health0.png");
	
}

void Health :: Update(){
	if(m_status){
		m_sprite.setTexture(m_texture);
	}else{
		m_sprite.setTexture(m_texHealth0);
	}
}

void Health :: setPosition(Vector2f pos){
	m_sprite.setPosition(pos);
	m_pos = pos;
}

void Health :: setStatus(bool status){
	m_status = status;
}

bool Health :: getStatus(){
	return m_status;
}

void Health :: setScale(Vector2f scale){
	m_sprite.setScale(scale);
}

Sprite Health :: getSprite(){
	return m_sprite;
}
