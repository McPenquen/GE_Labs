#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

// Entity manager
EntityManager em;

void Load() {
	// Create ghosts
	shared_ptr<Ghost> ghost1 = make_shared<Ghost>();
	em.list.push_back(move(ghost1));
	shared_ptr<Ghost> ghost2 = make_shared<Ghost>(Vector2f(200.f, 200.f), Color::Magenta);
	em.list.push_back(move(ghost2));
	shared_ptr<Ghost> ghost3 = make_shared<Ghost>(Vector2f(300.f, 400.f), Color::Blue);
	em.list.push_back(move(ghost3));
	shared_ptr<Ghost> ghost4 = make_shared<Ghost>(Vector2f(400.f, 600.f), Color::Green);
	em.list.push_back(move(ghost4));

	// Create player
	shared_ptr<Player> player = make_shared<Player>();
	em.list.push_back(move(player));
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
	em.Update(dt);
}

void Render(RenderWindow& window) {
	Renderer::intialise(window);
	// Render entities with entity manager
	em.Render();
	Renderer::render();
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