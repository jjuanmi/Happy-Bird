#include "Instructions.h"
#include "Game.h"
#include "Menu.h"

Instructions::Instructions() {
	setDefaults();
}

void Instructions::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		m_SpaceSelected = true;
	}
	
	if(m_clock.getElapsedTime().asSeconds() < 0.5){
		if((m_clock.getElapsedTime().asMilliseconds()) % 1 == 0){
			m_aux = m_aux-8;
			m_black.setFillColor({0,0,0,m_aux});
		}
	}
	
	if(m_clock.getElapsedTime().asSeconds() >= 5 or m_SpaceSelected){
		if((m_clock.getElapsedTime().asMilliseconds()) % 1 == 0){
			m_aux = m_aux+8;
			m_black.setFillColor({0,0,0,m_aux});
		}
		if(m_aux >= 255){game.setScene(new Menu());}
	}
}

void Instructions::Draw (RenderWindow & window) {
	window.clear(Color(0,150,255));
	
	window.draw(m_textTitle);
	window.draw(m_textMenu);
	window.draw(m_textGame);
	window.draw(m_textKeys);
	window.draw(m_textKeySpace);
	window.draw(m_textKeyUp);
	
	
	window.draw(m_sprKeys);
	window.draw(m_sprKeySpace);
	window.draw(m_sprKeyUp);
	
	window.draw(m_black);
	
	window.display();
}

void Instructions :: setDefaults(){
	m_font.loadFromFile("../fonts/8bitOperatorPlus8-Regular.ttf");
	m_fontTitle.loadFromFile("../fonts/KarmaFuture.ttf");
	
	m_textTitle.setFont(m_fontTitle);

	
	m_textTitle.setFont(m_fontTitle);
	m_textTitle.setString("Instructions:");
	m_textTitle.setFillColor(Color(255,255,255));
	m_textTitle.setPosition(360,0);
	m_textTitle.setCharacterSize(70);
	
	
	m_textMenu.setString("Menu and Shop: ");
	m_textMenu.setFont(m_fontTitle);
	m_textMenu.setPosition(10,90);
	
	m_textGame.setString("Game: ");
	m_textGame.setFont(m_fontTitle);
	m_textGame.setPosition(10,470);
	
	m_textKeys.setFont(m_font);
	m_textKeys.setString("Use to navigate through the options.");
	m_textKeys.setPosition(200,190);
	
	m_texKeys.loadFromFile("../models/buttons/keys.png");
	m_sprKeys.setTexture(m_texKeys);
	m_sprKeys.setScale(1.5,1.5);
	m_sprKeys.setPosition(20,160);
	
	
	m_textKeySpace.setFont(m_font);
	m_textKeySpace.setString("Use to select the option.");
	m_textKeySpace.setPosition(200,320);
	
	m_texKeySpace.loadFromFile("../models/buttons/key_space.png");
	m_sprKeySpace.setTexture(m_texKeySpace);
	m_sprKeySpace.setScale(1.5,1.5);
	m_sprKeySpace.setPosition(20,280);
	
	
	m_textKeyUp.setFont(m_font);
	m_textKeyUp.setString("Use to jump.");
	m_textKeyUp.setPosition(200,560);
	
	m_texKeyUp.loadFromFile("../models/buttons/key_up.png");
	m_sprKeyUp.setTexture(m_texKeyUp);
	m_sprKeyUp.setScale(1.5,1.5);
	m_sprKeyUp.setPosition(10,550);
	
	m_black.setSize(Vector2f(1300,720));
	m_black.setFillColor({0,0,0});	
}
