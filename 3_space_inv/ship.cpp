#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

// Ships
Ship::Ship() {}

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

Ship::~Ship() = default;

void Ship::moveDown() {}

void Ship::Explode() {
	setTextureRect(IntRect(128, 32, 32, 32));
	_exploded = true;
}

bool Ship::is_exploded() const {
	return _exploded;
}

// Invaders
Invader::Invader() : Ship() {
	_player = false;
}

Invader::Invader(IntRect ir, Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size(); ++i) {
			ships[i]->moveDown();
		}
	}

	static float firetime = 0.f;
	firetime -= dt;

	if (firetime <= 0 && rand() % 100 == 0) {
		Bullet::Fire(getPosition(), true);
		firetime = 4.0f + (rand() % 60);
	}
}

bool Invader::direction;
float Invader::speed;

void Invader::moveDown() {
	move(0, 24);
}

bool Ship::is_player() {
	return _player;
};

// Player
Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({gameHeight * 0.5f, gameHeight -32.f});
	_player = true;
}

void Player::Update(const float& dt) {
	Ship::Update(dt);

	float direction = .0f;
	if (Keyboard::isKeyPressed(Keyboard::Left) && (getPosition().x > 16)) {
		direction--;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && (getPosition().x < gameWidth - 16)) {
		direction++;
	}
	move(direction * 300.f * dt, 0);

	static float firetime = 0.0f;
	firetime -= dt;

	if (firetime <= 0 && Keyboard::isKeyPressed(Keyboard::Space)) {
		Bullet::Fire(getPosition(), false);
		firetime = 0.7f;
	}
}