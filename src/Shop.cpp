#include "Shop.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Game.h"
#include "Menu.h"

Shop::Shop() {
	ifstream file("../data.dat",ios::binary);
	file.seekg(0);
	file.read(reinterpret_cast<char*>(&m_totalPoints),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_bestScore),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_skinBird),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_skinTubo),sizeof(int));
	file.close();
	
	setDefaults();
}

void Shop::Update (Game & game) {
	
	m_textPoints.setString("Points: "+to_string(m_totalPoints));
	m_cloud1.Update();
	m_cloud2.Update();
	m_cloud3.Update();
	m_cloud4.Update();
	
	m_buttons[0].Update();
	m_buttons[1].Update();
	m_buttons[2].Update();
	m_buttons[3].Update();
	m_buttons[4].Update();
	m_buttons[5].Update();


	if(Keyboard::isKeyPressed(Keyboard::Key::Right) and !m_keyStatus){
		m_clickSound.play();
		
		m_buttons[m_buttonSelected].Unselect();
		
		++m_buttonSelected;
		
		if(m_buttonSelected == 6 ){m_buttonSelected = 0;}
		
		m_buttons[m_buttonSelected].Select();
		
		m_keyStatus = true;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Left) and !m_keyStatus){
		m_clickSound.play();
		
		m_buttons[m_buttonSelected].Unselect();
		
		--m_buttonSelected;
		
		if(m_buttonSelected == -1 ){m_buttonSelected = 5;}
		
		m_buttons[m_buttonSelected].Select();
		
		m_keyStatus = true;
		
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Up) and !m_keyStatus){
		m_clickSound.play();
		
		m_buttons[m_buttonSelected].Unselect();
		
		m_buttonSelected -= 3;
		
		if(m_buttonSelected == -3 ){m_buttonSelected = 3;}
		if(m_buttonSelected == -2 ){m_buttonSelected = 4;}
		if(m_buttonSelected == -1 ){m_buttonSelected = 5;}
		
		m_buttons[m_buttonSelected].Select();
		
		m_keyStatus = true;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Down) and !m_keyStatus){
		m_clickSound.play();
		
		m_buttons[m_buttonSelected].Unselect();
		
		m_buttonSelected += 3;
		
		if(m_buttonSelected == 6 ){m_buttonSelected = 0;}
		if(m_buttonSelected == 7 ){m_buttonSelected = 1;}
		if(m_buttonSelected == 8 ){m_buttonSelected = 2;}
		
		m_buttons[m_buttonSelected].Select();
		
		m_keyStatus = true;
	}
	
	
	if(!(Keyboard::isKeyPressed(Keyboard::Key::Right)||
		Keyboard::isKeyPressed(Keyboard::Key::Left) ||
		Keyboard::isKeyPressed(Keyboard::Key::Up)||
		Keyboard::isKeyPressed(Keyboard::Key::Down))){
		m_keyStatus = false;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)
	   and !m_spaceStatus and (m_buttonSelected >= 0 and m_buttonSelected <= 2)
	   and CanSelect()){
		m_selectedSound.play();
		
		UpdateSelected();
		ofstream file("../data.dat",ios::binary|ios::in);
		int aux;
		
		switch(m_buttonSelected){
		case 0:
			m_skinBird = 1;
			break;
		case 1:
			m_skinBird = 2;
			break;
		case 2:
			m_skinBird = 3;
			break;
		}
		
		file.write(reinterpret_cast<const char*>(&m_totalPoints), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_bestScore), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_skinBird), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_skinTubo), sizeof(int));
		file.close();
		
		m_spaceStatus = true;
		
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)
	   and !m_spaceStatus and (m_buttonSelected >= 3 and m_buttonSelected <= 5)
	   and CanSelect()){
		m_selectedSound.play();
		UpdateSelected();
		ofstream file("../data.dat",ios::binary|ios::out);
		
		switch(m_buttonSelected){
		case 3:
			m_skinTubo = 1;
			break;
		case 4:
			m_skinTubo = 2;
			break;
		case 5:
			m_skinTubo = 3;
			break;
		}
		file.write(reinterpret_cast<const char*>(&m_totalPoints), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_bestScore), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_skinBird), sizeof(int));
		file.write(reinterpret_cast<const char*>(&m_skinTubo), sizeof(int));
		file.close();
		
		m_spaceStatus = true;
	}
	
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Space) and !CanSelect() and !m_spaceStatus){
		m_errorSound.play();
		m_spaceStatus = true;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.setScene(new Menu());
	}
	if(!Keyboard::isKeyPressed(Keyboard::Key::Space))m_spaceStatus = false;
}

void Shop::Draw (RenderWindow & window) {
	window.clear(Color(0,150,255));
	
	m_cloud1.Draw(window);
	m_cloud2.Draw(window);
	m_cloud3.Draw(window);
	m_cloud4.Draw(window);
	
	window.draw(m_spriteMenu);
	
	window.draw(m_buttons[0].getSprite());
	window.draw(m_buttons[1].getSprite());
	window.draw(m_buttons[2].getSprite());
	window.draw(m_buttons[3].getSprite());
	window.draw(m_buttons[4].getSprite());
	window.draw(m_buttons[5].getSprite());
	
	window.draw(m_textPoints);
	window.draw(m_textBack);
	window.draw(m_text200points);
	window.draw(m_text300points);
	window.draw(m_text500points);
	window.draw(m_text600points);
	
	
	window.draw(m_spriteBird0);
	window.draw(m_spriteBird1);
	window.draw(m_spriteBird2);
	
	window.draw(m_spriteTubo0);
	window.draw(m_spriteTubo1);
	window.draw(m_spriteTubo2);
	
	if(m_totalPoints<200)window.draw(m_spriteLock0);
	if(m_totalPoints<300)window.draw(m_spriteLock1);
	if(m_totalPoints<500)window.draw(m_spriteLock2);
	if(m_totalPoints<600)window.draw(m_spriteLock3);
	
	window.draw(m_spriteSelected0);
	window.draw(m_spriteSelected1);
	
	window.display();
}

void Shop::setDefaults(){
//	setea el fondo del menu
	m_texMenu.loadFromFile("../models/buttons/menu.png");
	m_spriteMenu.setTexture(m_texMenu);
	m_spriteMenu.setPosition({140,60});
	m_spriteMenu.setScale(20,12);
	
	
	Button b1,b2,b3,b4,b5,b6;
	b1.setButtonScale({4,9.6});
	b2.setButtonScale({4,9.6});
	b3.setButtonScale({4,9.6});
	b4.setButtonScale({4,9.6});
	b5.setButtonScale({4,9.6});
	b6.setButtonScale({4,9.6});
	
	b1.setButtonPosition({300,190});
	b2.setButtonPosition({540,190});
	b3.setButtonPosition({780,190});
	b4.setButtonPosition({300,400});
	b5.setButtonPosition({540,400});
	b6.setButtonPosition({780,400});

	b1.Select();
	m_buttons = {b1,b2,b3,b4,b5,b6};
	
	
	m_cloud1.setCloudPosition({10,200});
	m_cloud2.setCloudPosition({490,0});
	m_cloud3.setCloudPosition({912,18});
	m_cloud4.setCloudPosition({1300,400});
	
	
	m_font.loadFromFile("../fonts/8bitOperatorPlus8-Regular.ttf");
	m_textPoints.setFont(m_font);
	m_textPoints.setString("Points: "+to_string(m_totalPoints));
	m_textPoints.setPosition(0,3);
	
	m_text200points.setFont(m_font);
	m_text200points.setString("200 points");
	m_text200points.setPosition(545,150);
	
	m_text300points.setFont(m_font);
	m_text300points.setString("300 points");
	m_text300points.setPosition(545,360);
	
	m_text500points.setFont(m_font);
	m_text500points.setString("500 points");
	m_text500points.setPosition(785,150);
	
	m_text600points.setFont(m_font);
	m_text600points.setString("600 points");
	m_text600points.setPosition(785,360);
	
	m_textBack.setFont(m_font);
	m_textBack.setString("Esc to back menu");
	m_textBack.setPosition(980,670);
	
	m_texBird0.loadFromFile("../models/birds/bird0.png");
	m_spriteBird0.setTexture(m_texBird0);
	m_spriteBird0.setPosition(350,230);
	m_spriteBird0.setScale(3,3);
	
	m_texBird1.loadFromFile("../models/birds/bird1.png");
	m_spriteBird1.setTexture(m_texBird1);
	m_spriteBird1.setPosition(590,230);
	m_spriteBird1.setScale(3,3);
	
	
	m_texBird2.loadFromFile("../models/birds/bird2.png");
	m_spriteBird2.setTexture(m_texBird2);
	m_spriteBird2.setPosition(830,230);
	m_spriteBird2.setScale(3,3);
	
	
	m_texTubo0.loadFromFile("../models/tubos/tubo0.png");
	m_spriteTubo0.setTexture(m_texTubo0);
	m_spriteTubo0.setPosition(380,415);
	m_spriteTubo0.setScale(1.2,1.2);
	
	
	m_texTubo1.loadFromFile("../models/tubos/tubo1.png");
	m_spriteTubo1.setTexture(m_texTubo1);
	m_spriteTubo1.setPosition(620,415);
	m_spriteTubo1.setScale(1.2,1.2);
	
	m_texTubo2.loadFromFile("../models/tubos/tubo2.png");
	m_spriteTubo2.setTexture(m_texTubo2);
	m_spriteTubo2.setPosition(860,415);
	m_spriteTubo2.setScale(1.2,1.2);
	
	m_texLock.loadFromFile("../models/buttons/lock_icon.png");
	
	m_spriteLock0.setTexture(m_texLock);
	m_spriteLock0.setScale(3,3);
	m_spriteLock0.setPosition(605,225);
	
	m_spriteLock1.setTexture(m_texLock);
	m_spriteLock1.setScale(3,3);
	m_spriteLock1.setPosition(605,435);
	
	m_spriteLock2.setTexture(m_texLock);
	m_spriteLock2.setScale(3,3);
	m_spriteLock2.setPosition(845,225);
	
	m_spriteLock3.setTexture(m_texLock);
	m_spriteLock3.setScale(3,3);
	m_spriteLock3.setPosition(845,435);
	
	m_texSelected.loadFromFile("../models/buttons/selected.png");
	m_spriteSelected0.setTexture(m_texSelected);
	m_spriteSelected0.setScale(4,9.6);
	
	m_spriteSelected0.setPosition(300,190);
	
	switch(m_skinBird){
	case 1:
		m_spriteSelected0.setPosition(300,190);
		break;
	case 2:
		m_spriteSelected0.setPosition(540,190);
		break;
	case 3:
		m_spriteSelected0.setPosition(780,190);
		break;
	}
	
	
	m_spriteSelected1.setTexture(m_texSelected);
	m_spriteSelected1.setScale(4,9.6);
	
	m_spriteSelected1.setPosition(300,400);
	switch(m_skinTubo){
	case 1:
		m_spriteSelected1.setPosition(300,400);
		break;
	case 2:
		m_spriteSelected1.setPosition(540,400);
		break;
	case 3:
		m_spriteSelected1.setPosition(780,400);
		break;
	}
	
	
	m_clickSoundBuffer.loadFromFile("../sounds/click_sound.ogg");
	m_clickSound.setBuffer(m_clickSoundBuffer);
	m_clickSound.setVolume(75);
	
	
	m_selectedSoundBuffer.loadFromFile("../sounds/selected_sound.ogg");
	m_selectedSound.setBuffer(m_selectedSoundBuffer);
	
	
	m_errorSoundBuffer.loadFromFile("../sounds/error_sound.ogg");
	m_errorSound.setBuffer(m_errorSoundBuffer);
}

void Shop::UpdateSelected(){
	
	switch(m_buttonSelected){
	case 0:
		m_spriteSelected0.setPosition(300,190);
		break;
	case 1:
		m_spriteSelected0.setPosition(540,190);
		break;
	case 2:
		m_spriteSelected0.setPosition(780,190);
		break;
	case 3:
		m_spriteSelected1.setPosition(300,400);
		break;
	case 4:
		m_spriteSelected1.setPosition(540,400);
		break;
	case 5:
		m_spriteSelected1.setPosition(780,400);
		break;
	}
}

bool Shop::CanSelect(){
	
	switch(m_buttonSelected){
	case 0:
		return true;
	case 1:
		if(m_totalPoints < 200) return false;
		else return true;
	case 2: 
		if(m_totalPoints < 500) return false;
		else return true;
	case 3:
		return true;
	case 4:
		if(m_totalPoints < 300) return false;
		else return true;
	case 5:
		if(m_totalPoints < 600) return false;
		else return true;
	}
}
