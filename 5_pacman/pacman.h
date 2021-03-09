#pragma once
#include <memory>
#include "scene.h"

using namespace std;
using namespace sf;

extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

class MenuScene : public Scene {
private:
	Text text;
	Font font;
public:
	MenuScene() = default;
	void Update(double dt) override;
	void Render() override;
	void Load() override;
};

class GameScene : public Scene {
private:
	Text text;
	Font font;
	Clock scoreClock;
	void Respawn();
	shared_ptr<Entity> player;
	vector<shared_ptr<Entity>> ghosts;

public:
	GameScene() = default;
	void Update(double dt) override;
	void Render() override;
	void Load() override;
};