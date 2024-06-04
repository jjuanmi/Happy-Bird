#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Shop.h"
#include <iostream>
#include "Instructions.h"
using namespace std;
using namespace sf;


Menu::Menu() {	
	setDefaults();
}

void Menu::Update(Game &game){
	m_buttonPlay.Update();
	m_buttonShop.Update();
	
	m_cloud1.Update();
	m_cloud2.Update();
	m_cloud3.Update();
	
	if(!Keyboard::isKeyPressed(Keyboard::Key::Space) and
	   (!m_buttonPlay.getStatus() and !m_buttonShop.getStatus())){
		m_buttonPlay.Select();
	}
	

	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space) and m_buttonPlay.getStatus()){
		m_selectedSound.play();
		m_musicSound.resetBuffer();
		game.setScene(new Match());
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Up) and !m_keyStatus){
		m_clickSound.play();
		m_buttonShop.Unselect();
		m_buttonPlay.Select();
		m_keyStatus = true;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Down) and !m_keyStatus){
		m_clickSound.play();
		m_buttonPlay.Unselect();
		m_buttonShop.Select();
		m_keyStatus = true;
	}
	
	if(!(Keyboard::isKeyPressed(Keyboard::Key::Up)||
		 Keyboard::isKeyPressed(Keyboard::Key::Down))){
		m_keyStatus = false;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space) and m_buttonShop.getStatus()){
		m_musicSound.resetBuffer();
		m_selectedSound.play();
		game.setScene(new Shop());
	}

	
	if(m_musicSound.getStatus() != Sound::Playing){
		m_musicSound.play();
	}
	
}

void Menu::Draw(RenderWindow &window){
	window.clear(Color(0,150,255));
	
	window.draw(m_cloud1.getSprite());
	window.draw(m_cloud2.getSprite());
	window.draw(m_cloud3.getSprite());
	
	
	window.draw(m_buttonPlay.getSprite());
	window.draw(m_buttonShop.getSprite());
	
	window.draw(m_textTitle);
	window.draw(m_textTitle1);
	
	window.display();
}


void Menu::setDefaults(){

	m_buttonPlay.setButtonPosition({520,350});
	m_buttonPlay.setButtonScale({5,5});
	m_texButtonPlay.loadFromFile("../models/buttons/button_play.png");
	m_texButtonPlayP.loadFromFile("../models/buttons/button_play_pressed.png");
	m_buttonPlay.setTextures(m_texButtonPlay,m_texButtonPlayP);
	
	
	m_buttonShop.setButtonPosition({520,480});
	m_buttonShop.setButtonScale({5,5});
	m_texButtonShop.loadFromFile("../models/buttons/button_shop.png");
	m_texButtonShopP.loadFromFile("../models/buttons/button_shop_pressed.png");
	m_buttonShop.setTextures(m_texButtonShop,m_texButtonShopP);
	
	
	m_cloud1.setCloudPosition({100,200});
	m_cloud2.setCloudPosition({490,0});
	m_cloud3.setCloudPosition({912,18});
	
	m_fontTitle.loadFromFile("../fonts/KarmaFuture.ttf");
	m_textTitle.setFont(m_fontTitle);
	m_textTitle.setString("Happy Bird");
	m_textTitle.setFillColor(Color(0,0,0));
	m_textTitle.setPosition(375,160);
	m_textTitle.setCharacterSize(100);
	
	m_textTitle1.setFont(m_fontTitle);
	m_textTitle1.setString("Happy Bird");
	m_textTitle1.setFillColor(Color(255,255,255));
	m_textTitle1.setPosition(370,150);
	m_textTitle1.setCharacterSize(100);
	
	m_clickSoundBuffer.loadFromFile("../sounds/click_sound.ogg");
	m_clickSound.setBuffer(m_clickSoundBuffer);
	m_clickSound.setVolume(75);
	
	m_selectedSoundBuffer.loadFromFile("../sounds/selected_sound.ogg");
	m_selectedSound.setBuffer(m_selectedSoundBuffer);
	
	m_musicSoundBuffer.loadFromFile("../sounds/music_sound.ogg");
	m_musicSound.setBuffer(m_musicSoundBuffer);
	m_musicSound.setVolume(30);
}


