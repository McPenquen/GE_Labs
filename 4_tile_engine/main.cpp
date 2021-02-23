#include <SFML/Graphics.hpp>
#include "game.h"
#include "player.h"
#include "LevelSystem.h"
#include <iostream>

using namespace sf;
using namespace std;

unique_ptr<Player> player;

void Load() {
	player = make_unique<Player>();
	LS::loadLevelFile("res/maze1.txt");
	for (size_t y = 0; y < LS::getHeight(); ++y) {
		for (size_t x = 0; x < LS::getWidth(); ++x) {
			cout << LS::getTile({ x, y });
		}
		cout << endl;
	}
}

void Update(RenderWindow& window) {
	// Get delta time
	static Clock clock;
	float dt = clock.restart().asSeconds();

	// ESC quit
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	player->Update(dt);
}

void Render(RenderWindow& window) {
	LS::Render(window);
	player->Render(window);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "TILE ENG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
  return 0;
}