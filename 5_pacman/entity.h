#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "lib_ecm.h"

using namespace sf;
using namespace std;

class Player : public Entity {
public:
	Player();
	~Player() = default;
};

class Ghost : public Entity {
public:
	Ghost();
	~Ghost() = default;
};

struct EntityManager {
	vector<shared_ptr<Entity>> list;
	void Update(double dt);
	void Render();
};