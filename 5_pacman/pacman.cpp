#include "pacman.h"
#include "system_renderer.h"
#include "game.h"
#include "cmp_sprite.h"

#define GHOSTS_COUNT 4

shared_ptr<Scene> gameScene;
shared_ptr<Scene> menuScene;
shared_ptr<Scene> activeScene;

// Menu Scene
void MenuScene::Update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::Update(dt);
	text.setString("MENU PaC-MaN");
}

void MenuScene::Render() {
	Renderer::Queue(&text);
	Scene::Render();
}

void MenuScene::Load() {
	font.loadFromFile("res/fonts/Roboto-Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition((gameWidth * .4f) - (text.getLocalBounds().width * .4f), 0);
}

// Game Scene
void GameScene::Update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::Update(dt);
	text.setString("PAC-MAN");
}

void GameScene::Render() {
	Renderer::Queue(&text);
	Scene::Render();
}

void GameScene::Load() {
	// Setup text
	font.loadFromFile("res/fonts/Roboto-Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition((gameWidth * .4f) - (text.getLocalBounds().width * .4f), 0);

	// Create player
	auto player = make_shared<Entity>();
	auto s = player->addComponent<ShapeComponent>();
	s->setShape<sf::CircleShape>(12.f);
	s->getShape().setFillColor(Color::Yellow);
	s->getShape().setOrigin(Vector2f(12.f, 12.f));
	player->setPosition({200.f, 200.f});
	_ents.list.push_back(move(player));

	// Create ghosts
	const Color ghost_cols[]{ {208, 62, 25},    // red Blinky
							 {219, 133, 28},   // orange Clyde
							 {70, 191, 238},   // cyan Inky
							 {234, 130, 229} }; // pink Pinky

	for (int i = 0; i < GHOSTS_COUNT; i++) {
		auto ghost = make_shared<Entity>();
		auto s1 = ghost->addComponent<ShapeComponent>();
		s1->setShape<sf::CircleShape>(12.f);
		s1->getShape().setFillColor(ghost_cols[i % 4]);
		s1->getShape().setOrigin(Vector2f(12.f, 12.f));
		ghost->setPosition({400.f + i * 20.f, 440.f});
		_ents.list.push_back(ghost);
	}

}