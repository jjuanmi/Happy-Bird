#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <fstream>
using namespace std;
using namespace sf;

class Game {
public:
	Game();
	void Run();
	void ProcessEvents();
	void Update();
	void Draw();
	void setScene(Scene *m_nextScene);
private:
	RenderWindow m_window;
	Scene *m_scene;
	Scene *m_nextScene = nullptr;
	Image icon;
};

#endif

