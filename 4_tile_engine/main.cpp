#include <SFML/Graphics.hpp>
#include "game.h"
#include "player.h"

using namespace sf;
using namespace std;

unique_ptr<Player> player;

void Load() {
	player = make_unique<Player>();
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