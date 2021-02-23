#pragma once
#include "entity.h"

using namespace sf;

class Player : public Entity {
private:
	float _speed;

public:
	Player();
	void Update(double dt) override;
	void Render(RenderWindow& window) const override;
};