#include "cmp_actor_movement.h"
#include "game.h"
#include "LevelSystem.h"

using namespace std;
using namespace sf;

// Helper functions
float getRandomNumber(int maxVal, int minVal) {
	float answer = floor(rand() % maxVal + minVal);
	return answer;
}

// ActorMovementComponent
void ActorMovementComponent::Update(double dt) {}

ActorMovementComponent::ActorMovementComponent(Entity* p) : _speed(100.0f), Component(p){}

ActorMovementComponent::~ActorMovementComponent() {}

float ActorMovementComponent::getSpeed() const { return _speed; }

void ActorMovementComponent::setSpeed(float new_speed) { _speed = new_speed; }

bool ActorMovementComponent::validMove(const Vector2f& pos) {
	return LS::getTileAt(pos) != LS::WALL;
}

void ActorMovementComponent::move(const Vector2f& p) {
	auto pp = _parent->getPosition() + p;

	if (validMove(pp)) {
		_parent->setPosition(pp);
	}
}

void ActorMovementComponent::move(float x, float y) {
	move(Vector2f(x, y));
}

// PlayerMovementComponent
PlayerMovementComponent::PlayerMovementComponent(Entity* p) : ActorMovementComponent(p) {}

void PlayerMovementComponent::Update(double dt) {
	if (_parent->isAlive()) {
		Vector2f direction = { 0.f, 0.f };
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			direction.x = -_speed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			direction.x = _speed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			direction.y = _speed * dt;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			direction.y = -_speed * dt;
		}

		if (_parent->getPosition().x - 15.f > 0 &&
			_parent->getPosition().x + 15.f < gameWidth &&
			_parent->getPosition().y - 15.f > 0 &&
			_parent->getPosition().y + 15.f < gameHeight) {
			move(direction);
		}
		else {
			if (_parent->getPosition().x - 15.f <= 0 && direction.x < 0) {
				direction.x = 0;
			}
			else if (_parent->getPosition().x + 15.f >= gameWidth && direction.x > 0) {
				direction.x = 0;
			}
			if (_parent->getPosition().y - 15.f <= 0 && direction.y < 0) {
				direction.y = 0;
			}
			else if (_parent->getPosition().y + 15.f >= gameHeight && direction.y > 0) {
				direction.y = 0;
			}
			move(direction);
		}
	}
}

// EnemyMovementComponent
EnemyMovementComponent::EnemyMovementComponent(Entity* p) : ActorMovementComponent(p) {}

void EnemyMovementComponent::Update(double dt) {
	if (_parent->isAlive()) {
		// Random movement generation
		if (directionChangeTime <= 0.0f) {
			float randSign1 = getRandomNumber(2, 0) == 1 ? -1.f : 1.f;
			float randSign2 = getRandomNumber(2, 0) == 1 ? -1.f : 1.f;
			float zeroChance1 = getRandomNumber(2, 0) == 1 ? 0.f : 1.f;
			float zeroChance2 = 1.f;
			if (zeroChance1 != 0.0f) {
				zeroChance2 = getRandomNumber(2, 0) == 1 ? 0.f : 1.f;
			}
			movementDirection = { _speed * randSign1 * zeroChance1,
				_speed * randSign2 * zeroChance2 };
			directionChangeTime = getRandomNumber(5, 1);
		}

		directionChangeTime -= float(dt);
		// Colision detected movement
		if (_parent->getPosition().x - 15.f > 0 &&
			_parent->getPosition().x + 15.f < gameWidth &&
			_parent->getPosition().y - 15.f > 0 &&
			_parent->getPosition().y + 15.f < gameHeight) {
			//move(Vector2f(movementDirection.x * dt, movementDirection.y * dt));
		}
		else {
			if (_parent->getPosition().x - 15.f <= 0 && movementDirection.x < 0) {
				movementDirection.x *= -1.f;
			}
			else if (_parent->getPosition().x + 15.f >= gameWidth && movementDirection.x > 0) {
				movementDirection.x *= -1.f;
			}
			if (_parent->getPosition().y - 15.f <= 0 && movementDirection.y < 0) {
				movementDirection.y *= -1.f;
			}
			else if (_parent->getPosition().y + 15.f >= gameHeight && movementDirection.y > 0) {
				movementDirection.y *= -1.f;
			}
			//move(Vector2f(movementDirection.x * dt, movementDirection.y * dt));
		}

	}
}
