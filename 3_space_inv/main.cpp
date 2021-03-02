#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

// Graphics
Texture spritesheet;

// All ships
vector<Ship*> ships;

void Load() {
	if (!spritesheet.loadFromFile("res/sprints/invaders_sheet.png")) {
		cerr << "Failed to load sprintsheet" << endl;
	}

	Invader::direction = true;
	Invader::speed = 100.0f;

	for (int i = 0; i < invaders_rows; i++) {
		for (int j = 0; j < invaders_columns; j++) {
			Invader* inv = new Invader(IntRect(i * 32, 0, 32, 32), { float(20 + j * 32), float(20 + i * 32)});
			ships.push_back(inv);
		}
	}

	Player* p = new Player();
	ships.push_back(p);
}


void Update(RenderWindow& window) {
	// Get delta time
	static Clock clock;
	float dt = clock.restart().asSeconds();

	// ESC quit
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	
	// Update all ships
	for (auto &s : ships) {
		s->Update(dt);
	}
	Bullet::Update(dt);
}

void Render(RenderWindow& window) {
	for (const auto s : ships) {
		window.draw(*s);
	}
	Bullet::Render(window);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "I N V A D E R S");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}

