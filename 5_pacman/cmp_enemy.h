#pragma once
#include <SFML/Graphics.hpp>
#include "cmp_actor_movement.h"

using namespace std;
using namespace sf;

class EnemyAIComponent : public ActorMovementComponent {
protected: 
	Vector2f _direction = {0, 1};
	enum state {ROAMING, ROTATING, ROTATED};
	state _state;
public:
	EnemyAIComponent(Entity* p);
	EnemyAIComponent() = delete;
	~EnemyAIComponent() = default;
	void Update(double dt) override;
};
