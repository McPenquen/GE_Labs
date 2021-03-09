#include "entity.h"
#include "game.h"
#include "system_renderer.h"
#include <iostream>

using namespace std;
using namespace sf;

// Player
Player::Player() {}

// Ghost
Ghost::Ghost() {}

// EntityManager
void EntityManager::Render() {
	for (const auto& e : list) {
		e->Render();
	}
}

void EntityManager::Update(double dt) {
	for (auto& e : list) {
		e->Update(dt);
	}
}
