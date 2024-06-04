#include "Match.h"
#include "Game.h"
#include "Menu.h"
#include <iostream>
using namespace std;


Match::Match() {
	ifstream file("../data.dat",ios::binary);
	file.seekg(0);
	file.read(reinterpret_cast<char*>(&m_totalPoints),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_bestScore),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_skinBird),sizeof(int));
	file.read(reinterpret_cast<char*>(&m_skinTubo),sizeof(int));
	file.close();
	
	m_textPoints.setString(to_string(m_points));
	m_textGameOver.setFont(m_font2);

	setDefaults();
}
///
void Match::Update(Game &game){
	m_h1.Update();
	m_h2.Update();
	m_h3.Update();
	
	if(m_bird.isAlive()){
		
		AddPoint();
		AddHealth();
		
		m_cloud1.Update();
		m_cloud2.Update();
		m_cloud3.Update();
		m_additionalHealth.Update();
		
		m_bird.Update();
		m_tubo.Update();
		m_textPoints.setString(to_string(m_points));
		DetectCollision();
		
		if((m_points)%10 == 0 and !m_shouldAddSpeed){
			m_tubo.AddSpeed();
			m_additionalHealth.AddSpeed();
			m_shouldAddSpeed = true;
		}
		
		if(m_points%10 == 1){
			m_shouldAddSpeed = false;
		}
		
		
		if(m_additionalHealth.getSprite().getPosition().x <= -120){
			SpawnAdditionalHealth();
		}
		
		
	} else {
		if(!m_showGameOverScreen and !m_bird.isAlive()){
			GameOverScreen();
			m_deadSound.play();
		}
		
		m_buttonPlay.Update();
		m_buttonMenu.Update();
		
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Left) and !m_keyStatus){
			m_buttonMenu.Unselect();
			m_buttonPlay.Select();
			m_keyStatus = true;
			m_clickSound.play();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Right) and !m_keyStatus){
			m_buttonPlay.Unselect();
			m_buttonMenu.Select();
			m_keyStatus = true;
			m_clickSound.play();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Space) and m_buttonMenu.getStatus()){
			game.setScene(new Menu());
			m_selectedSound.play();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Space) and m_buttonPlay.getStatus() and !m_spaceKeyPressed){
			
			m_spaceKeyPressed = true;
			PlayAgain();
			
			m_selectedSound.play();
		} else if(!Keyboard::isKeyPressed(Keyboard::Key::Space)){
			
			m_spaceKeyPressed = false;
			
		}
		if(!(Keyboard::isKeyPressed(Keyboard::Key::Right)||
			 Keyboard::isKeyPressed(Keyboard::Key::Left))){
			m_keyStatus = false;
		}
	}
	ResetShouldAddPoint();
}

void Match::Draw(RenderWindow &window){
	window.clear(Color(0,150,255));
	
	m_cloud1.Draw(window);
	m_cloud2.Draw(window);
	m_cloud3.Draw(window);
	
	m_tubo.Draw(window);
	m_bird.Draw(window);
	
	window.draw(m_additionalHealth.getSprite());
	
	if(!m_bird.isAlive() and m_showGameOverScreen){
		window.draw(m_gameOverMenu);
		window.draw(m_textBest);
		window.draw(m_textTotalPoints);
		window.draw(m_textGameOver);
		window.draw(m_buttonPlay.getSprite());
		window.draw(m_buttonMenu.getSprite());
	}
	
	window.draw(m_h1.getSprite());
	window.draw(m_h2.getSprite());
	window.draw(m_h3.getSprite());
	
	
	window.draw(m_textPoints);
	window.display();
	
}

void Match::DetectCollision(){
	
	if (m_bird.getHitBox().intersects(m_tubo.getHitBox1()) && !m_collisionDetected) {
		m_collisionDetected = true;
		m_shouldAddPoint = false;
		m_hitSound.play();
		
		if (m_h3.getStatus()) {
			m_h3.setStatus(false);
		} else if (m_h2.getStatus()) {
			m_h2.setStatus(false);
		} else if (m_h1.getStatus()) {
			m_h1.setStatus(false);
		}
		m_bird.HitAnimation();
	}
	
	if (m_bird.getHitBox().intersects(m_tubo.getHitBox2()) && !m_collisionDetected) {
		m_collisionDetected = true;
		m_shouldAddPoint = false;
		m_hitSound.play();
		
		if (m_h3.getStatus()) {
			m_h3.setStatus(false);
		} else if (m_h2.getStatus()) {
			m_h2.setStatus(false);
		} else if (m_h1.getStatus()) {
			m_h1.setStatus(false);
		}
		m_bird.HitAnimation();
	}
	
	if(m_bird.getPosition().y >= 750){
		m_collisionDetected = true;
		m_shouldAddPoint = false;
		m_hitSound.play();
		
		m_h3.setStatus(false);
		m_h2.setStatus(false);
		m_h1.setStatus(false);
		
		m_bird.HitAnimation();
	}
	
	if(!m_bird.getHitBox().intersects(m_tubo.getHitBox1()) and !m_bird.getHitBox().intersects(m_tubo.getHitBox2())){
		m_collisionDetected = false;
	}
	
	if(m_h1.getStatus() or m_h2.getStatus() or m_h3.getStatus()){
	} else {
		m_bird.Dead();
	}
}

void Match::AddPoint(){
	if(m_bird.getHitBox().intersects(m_tubo.getHitBox3()) and !m_pointAdded and m_shouldAddPoint){
		++m_points;
		m_pointAdded = true;
		m_coinSound.play();
	} else if(!m_bird.getHitBox().intersects(m_tubo.getHitBox3())){
		m_pointAdded = false;
	}	
}

void Match::setDefaults(){
	
	m_tubo.setTuboSpeed({-11,0});
	m_tubo.setTuboPosition(m_tubo.GeneratePosition());
	
	m_cloud1.setCloudPosition({1280,0});
	m_cloud2.setCloudPosition({1800,100});
	m_cloud3.setCloudPosition({2200,100});
	
	m_cloud1.setSpeed({-3,0});
	m_cloud2.setSpeed({-3,0});
	m_cloud3.setSpeed({-3,0});
	
	m_buttonPlay.setButtonScale({4,4});	
	m_buttonPlay.setButtonPosition({-100,-100});
	m_texButtonPlay.loadFromFile("../models/buttons/button_play.png");
	m_texButtonPlayP.loadFromFile("../models/buttons/button_play_pressed.png");
	m_buttonPlay.setTextures(m_texButtonPlay,m_texButtonPlayP);
	m_buttonPlay.Select();
	
	m_buttonMenu.setButtonScale({4,4});	
	m_buttonMenu.setButtonPosition({-100,-100});
	m_texButtonMenu.loadFromFile("../models/buttons/button_menu.png");
	m_texButtonMenuP.loadFromFile("../models/buttons/button_menu_pressed.png");
	m_buttonMenu.setTextures(m_texButtonMenu,m_texButtonMenuP);
	
	
	
	m_font1.loadFromFile("../fonts/8bitoperatorplus8-bold.ttf");
	m_font2.loadFromFile("../fonts/karmafuture.ttf");
	m_menuTexture.loadFromFile("../models/buttons/menu.png");
	m_textPoints.setFont(m_font1);
	m_textPoints.setCharacterSize(80);
	m_textPoints.setFillColor(Color(255,255,255));
	m_textPoints.setPosition(10,-15);
	
	
	m_coinSoundBuffer.loadFromFile("../sounds/coin_sound.ogg");
	m_coinSound.setBuffer(m_coinSoundBuffer);
	
	m_deadSoundBuffer.loadFromFile("../sounds/dead_sound.ogg");
	m_deadSound.setBuffer(m_deadSoundBuffer);
	
	m_clickSoundBuffer.loadFromFile("../sounds/click_sound.ogg");
	m_clickSound.setBuffer(m_clickSoundBuffer);
	m_clickSound.setVolume(75);
	
	m_selectedSoundBuffer.loadFromFile("../sounds/selected_sound.ogg");
	m_selectedSound.setBuffer(m_selectedSoundBuffer);
	
	m_coinSound.setVolume(50);
	m_deadSound.setVolume(25);
	
	m_hitSoundBuffer.loadFromFile("../sounds/hit_sound.ogg");
	m_hitSound.setBuffer(m_hitSoundBuffer);
	
	m_h1.setScale({1.7,1.7});
	m_h2.setScale({1.7,1.7});
	m_h3.setScale({1.7,1.7});
	
	m_h1.setPosition({5,675});
	m_h2.setPosition({55,675});
	m_h3.setPosition({105,675});
	
	m_additionalHealth.setSpeed({-11,0});
	m_additionalHealth.setPosition({600,-100});
	m_additionalHealth.setScale({2,2});
	
}

void Match::GameOverScreen(){
	cout<<"Game over Screen"<<endl;
	
	if(m_points>m_bestScore)m_bestScore = m_points;
	m_totalPoints +=m_points;
	
	ofstream file("../data.dat",ios::binary);
	file.write(reinterpret_cast<const char*>(&m_totalPoints), sizeof(int));
	file.write(reinterpret_cast<const char*>(&m_bestScore), sizeof(int));
	file.write(reinterpret_cast<const char*>(&m_skinBird), sizeof(int));
	file.write(reinterpret_cast<const char*>(&m_skinTubo), sizeof(int));
	file.close();
	
	
	m_showGameOverScreen = true;
	
	m_gameOverMenu.setTexture(m_menuTexture);
	m_gameOverMenu.setScale(12,10);
	m_gameOverMenu.setPosition({340,110});
	
	m_textGameOver.setString("GameOver");
	m_textGameOver.setCharacterSize(80);
	m_textGameOver.setPosition({445,155});
	
	m_textTotalPoints.setFont(m_font1);
	m_textTotalPoints.setString("Total: ");
	m_textTotalPoints.setCharacterSize(50);
	m_textTotalPoints.setPosition({400,290});
	
	m_textPoints.setCharacterSize(50);
	m_textPoints.setPosition(585,290);
	
	m_textBest.setFont(m_font1);
	m_textBest.setString("Best: "+to_string(m_bestScore));
	m_textBest.setCharacterSize(50);
	m_textBest.setPosition({400,370});
	
	m_buttonPlay.setButtonPosition({425,470});
	m_buttonMenu.setButtonPosition({650,470});
}

void Match::PlayAgain(){
	cout<<"Play Again!!"<<endl;
	m_tubo.setTuboPosition(m_tubo.GeneratePosition());
	m_tubo.setTuboSpeed({-11,0});
	
	m_bird.setBirdPosition({600,300});
	m_bird.setBirdSpeed({1,1});
	
	m_cloud1.setCloudPosition({1280,0});
	m_cloud2.setCloudPosition({1800,100});
	m_cloud3.setCloudPosition({2200,100});
	
	m_textPoints.setCharacterSize(80);
	m_textPoints.setPosition(10,-15);
	m_points = 0;
	
	m_h1.setStatus(true);
	m_h2.setStatus(true);
	m_h3.setStatus(true);
	
	m_additionalHealth.setSpeed({-11,0});
	m_additionalHealth.setPosition({600,-100});
	
	m_shouldAddPoint = true;
	
	m_bird.Revive();
	
	m_showGameOverScreen = false;
}

void Match :: ResetShouldAddPoint(){
	if(m_tubo.getPosition().x < 20){
		m_shouldAddPoint = true;
	}
}

void Match :: SpawnAdditionalHealth(){
	int n;
	if(m_h1.getStatus() and m_h2.getStatus() and m_h3.getStatus()){
		m_additionalHealth.setPosition({m_additionalHealth.GeneratePosition().x,-100});
	}
	if(m_h1.getStatus() and m_h2.getStatus() and !m_h3.getStatus()){
		n = rand()%5;
		if(n == 1){
			m_additionalHealth.setPosition({m_additionalHealth.GeneratePosition()});
		} else {
			m_additionalHealth.setPosition({m_additionalHealth.GeneratePosition().x,-100});
		}
	}
	if(m_h1.getStatus() and !m_h2.getStatus() and !m_h3.getStatus()){
		n = rand()%2;
		if(n == 1){
			m_additionalHealth.setPosition({m_additionalHealth.GeneratePosition()});
		} else {
			m_additionalHealth.setPosition({m_additionalHealth.GeneratePosition().x,-100});
		}
	}
}

void Match :: AddHealth(){
	if(m_bird.getHitBox().intersects(m_additionalHealth.getSprite().getGlobalBounds()) and !m_healthAdded){
		m_healthAdded = true;
		m_coinSound.play();
		if(m_h1.getStatus() and m_h2.getStatus() and !m_h3.getStatus()){
			m_h3.setStatus(true);
			m_additionalHealth.setPosition({m_additionalHealth.getSprite().getPosition().x,-100});
		}
		if(m_h1.getStatus() and !m_h2.getStatus() and !m_h3.getStatus()){
			m_h2.setStatus(true);
			m_additionalHealth.setPosition({m_additionalHealth.getSprite().getPosition().x,-100});
		}
	} else if(!m_bird.getHitBox().intersects(m_additionalHealth.getSprite().getGlobalBounds())){
		m_healthAdded = false;
	}	
}
