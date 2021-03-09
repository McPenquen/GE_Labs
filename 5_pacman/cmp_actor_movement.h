#pragma once
#include <lib_ecm.h>

using namespace std;
using namespace sf;

class ActorMovementComponent : public Component {
protected:
	bool validMove(const Vector2f&);
	float _speed;

public:
	explicit ActorMovementComponent(Entity* p);
	ActorMovementComponent() = delete;
	~ActorMovementComponent();

	float getSpeed() const;
	void setSpeed(float new_speed);

	void move(const Vector2f&);
	void move(float x, float y);

	void Render() override {}
	void Update(double dt) override;
};

class PlayerMovementComponent : public ActorMovementComponent {
public:
	PlayerMovementComponent(Entity* p);
	PlayerMovementComponent() = delete;
	~PlayerMovementComponent() = default;
	void Update(double dt) override;
};

class EnemyMovementComponent : public ActorMovementComponent {
protected:
	float directionChangeTime = 0.f;
	Vector2f movementDirection;
public:
	EnemyMovementComponent(Entity* p);
	EnemyMovementComponent() = delete;
	~EnemyMovementComponent() = default;
	void Update(double dt) override;
};