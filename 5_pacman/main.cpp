#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"
#include "system_renderer.h"
#include "pacman.h"
#include <iostream>

using namespace sf;
using namespace std;

double passedTime = 0.0;

void Load() {
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->Load();
	menuScene->Load();
	activeScene = menuScene;
}

void Update(RenderWindow& window) {
	// Get delta time
	static Clock clock;
	double dt = clock.restart().asSeconds();
	passedTime += dt;
	cout << passedTime << endl;
	activeScene->Update(dt);

	if (passedTime > 20.0) {
		activeScene->getEnts()[2]->setForDelete();
	}

	// ESC quit
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Render(RenderWindow& window) {
	// Render entities with entity manager
	activeScene->Render();
	Renderer::Render();
}

int main(){
	RenderWindow window(VideoMode(gameWidth, gameHeight), "P A C - M A N");
	Renderer::Intialise(window);
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}