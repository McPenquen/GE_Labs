#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// Window settings
const int gameWidth = 800;
const int gameHeight = 600;

// Graphics
Texture sprintsheet;
Sprite invader;

void Load() {
	if (!sprintsheet.loadFromFile("res/sprints/invaders_sheet.png")) {
		cerr << "Failed to load sprintsheet" << endl;
	}
	invader.setTexture(sprintsheet);
	invader.setTextureRect(IntRect(0, 0, 32, 32));
}


void Update(RenderWindow& window) {

}

void Render(RenderWindow& window) {
	window.draw(invader);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "I N V A D O R S");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}

