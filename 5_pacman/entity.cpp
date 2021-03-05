#include "entity.h"
#include "game.h"
#include "system_renderer.h"
#include <iostream>

using namespace std;
using namespace sf;

// Helper functions
float getRandomNumber(int maxVal, int minVal) {
	float answer = floor(rand() % maxVal + minVal);
	return answer;
}

// Entity
/*
const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(double dt) {
	_shape->setPosition(_position);
}

Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}
*/
// Player
Player::Player() : _speed(200.0f) {
	this->setPosition(Vector2f(400.f, 400.f));
}
/*
void Player::Update(double dt) {
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
	
	if (getPosition().x - 15.f > 0 &&
		getPosition().x + 15.f < gameWidth &&
		getPosition().y - 15.f > 0 &&
		getPosition().y + 15.f < gameHeight) {
		move(direction);
	}
	else {
		if (getPosition().x - 15.f <= 0 && direction.x < 0) {
			direction.x = 0;
		}
		else if (getPosition().x + 15.f >= gameWidth && direction.x > 0) {
			direction.x = 0;
		}
		if (getPosition().y - 15.f <= 0 && direction.y < 0) {
			direction.y = 0;
		}
		else if (getPosition().y + 15.f >= gameHeight && direction.y > 0) {
			direction.y = 0;
		}
		move(direction);
	}

	Entity::Update(dt);
}
*/
/*
void Player::Render() {
	Renderer::Queue(_shape.get());
}
*/
// Ghost
float Ghost::_speed = 100.f;

Ghost::Ghost() {
	this->setPosition(Vector2f(600.f, 500.f));
}

Ghost::Ghost(Vector2f new_pos) {
	this->setPosition(new_pos);
}
/*
void Ghost::Update(double dt) {
	// Random movement generation
	if (directionChangeTime <= 0.0f) {
		float randSign1 = getRandomNumber(2, 0) == 1 ? -1.f : 1.f;
		float randSign2 = getRandomNumber(2, 0) == 1 ? -1.f : 1.f;
		float zeroChance1 = getRandomNumber(2, 0) == 1 ? 0.f : 1.f;
		float zeroChance2 = 1.f;
		if (zeroChance1 != 0.0f) {
			zeroChance2 = getRandomNumber(2, 0) == 1 ? 0.f : 1.f;
		}
		movementDirection = {_speed * randSign1 * zeroChance1,
			_speed * randSign2 * zeroChance2};
		directionChangeTime = getRandomNumber(5, 1);
	}

	directionChangeTime -= float(dt);
	// Colision detected movement
	if (getPosition().x - 15.f > 0 && 
		getPosition().x + 15.f < gameWidth && 
		getPosition().y - 15.f > 0 &&
		getPosition().y + 15.f < gameHeight) {
		move(Vector2f(movementDirection.x * dt, movementDirection.y * dt));
	}
	else {
		if (getPosition().x - 15.f <= 0 && movementDirection.x < 0) {
			movementDirection.x *= -1.f;
		}
		else if (getPosition().x + 15.f >= gameWidth && movementDirection.x > 0) {
			movementDirection.x *= -1.f;
		}
		if (getPosition().y - 15.f <= 0 && movementDirection.y < 0) {
			movementDirection.y *= -1.f;
		}
		else if (getPosition().y + 15.f >= gameHeight && movementDirection.y > 0) {
			movementDirection.y *= -1.f;
		}
		move(Vector2f(movementDirection.x *dt, movementDirection.y *dt));
	}

	Entity::Update(dt);
}
*/
/*
void Ghost::Render() {
	Renderer::Queue(_shape.get());
}
*/
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
