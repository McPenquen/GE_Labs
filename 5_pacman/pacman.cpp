#include "pacman.h"
#include "system_renderer.h"
#include "game.h"

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
	// Create ghosts
	shared_ptr<Ghost> ghost1 = make_shared<Ghost>();
	_ents.list.push_back(move(ghost1));
	shared_ptr<Ghost> ghost2 = make_shared<Ghost>(Vector2f(200.f, 200.f), Color::Magenta);
	_ents.list.push_back(move(ghost2));
	shared_ptr<Ghost> ghost3 = make_shared<Ghost>(Vector2f(300.f, 400.f), Color::Blue);
	_ents.list.push_back(move(ghost3));
	shared_ptr<Ghost> ghost4 = make_shared<Ghost>(Vector2f(400.f, 600.f), Color::Green);
	_ents.list.push_back(move(ghost4));

	// Create player
	shared_ptr<Player> player = make_shared<Player>();
	_ents.list.push_back(move(player));
}