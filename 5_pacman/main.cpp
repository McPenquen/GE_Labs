#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

using namespace sf;
using namespace std;

// Entities
vector<unique_ptr<Entity>> entities;

void Load() {
	// Create ghosts
	unique_ptr<Ghost> ghost1 = make_unique<Ghost>();
	entities.push_back(move(ghost1));
	unique_ptr<Ghost> ghost2 = make_unique<Ghost>(Vector2f(200.f, 200.f), Color::Magenta);
	entities.push_back(move(ghost2));
	unique_ptr<Ghost> ghost3 = make_unique<Ghost>(Vector2f(300.f, 400.f), Color::Blue);
	entities.push_back(move(ghost3));
	unique_ptr<Ghost> ghost4 = make_unique<Ghost>(Vector2f(400.f, 600.f), Color::Green);
	entities.push_back(move(ghost4));

	// Create player
	unique_ptr<Player> player = make_unique<Player>();
	entities.push_back(move(player));
}

void Update(RenderWindow& window) {
	// Get delta time
	static Clock clock;
	float dt = clock.restart().asSeconds();

	// ESC quit
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	// Update entities
	for (auto &e : entities) {
		e->Update(dt);
	}
}

void Render(RenderWindow& window) {
	// Render entities
	for (const auto &e : entities) {
		e->Render(window);
	}
}

int main(){
	RenderWindow window(VideoMode(gameWidth, gameHeight), "P A C - M A N");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}