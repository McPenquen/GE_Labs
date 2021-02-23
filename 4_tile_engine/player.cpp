#include "player.h"

using namespace std;
using namespace sf;

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Red);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Update(double dt) {
	Vector2f direction = {0.f, 0.f};
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
	move(direction);
	Entity::Update(dt);
}

void Player::Render(RenderWindow& window) const {
	window.draw(*_shape);
}