#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;
class Game;


class Scene {
public:
	Scene();
	virtual void Update(Game &game) = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual void ProcessEvents(Event &e){}
private:
};

#endif

