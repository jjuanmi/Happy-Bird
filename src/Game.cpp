#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Instructions.h"
using namespace sf;

Game::Game():m_window(VideoMode(1280,720),"Happy Bird"){
	m_window.setFramerateLimit(60);
	m_scene = new Instructions();
	icon.loadFromFile("../models/icon.png");
}

void Game::Run(){
	m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if(m_nextScene){
			delete m_scene;
			m_scene = m_nextScene;
			m_nextScene = nullptr;
		}
	}
}

void Game::Update(){
	m_scene->Update(*this);
}

void Game::Draw(){
	m_scene->Draw(m_window);
}

void Game::ProcessEvents(){
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();
		if (e.key.code == Keyboard::F1)
			m_window.close();
		m_scene->ProcessEvents(e);
	}
	
}

void Game::setScene(Scene *m_nextScene){
	m_scene = m_nextScene;
}
