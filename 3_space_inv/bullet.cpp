#include "bullet.h"
#include "game.h"

using namespace sf;
using namespace std;

Bullet::Bullet() {}

void Bullet::Update(const float& dt) {
	for (auto& b : bullets) {
		b._Update(dt);
	}
}

void Bullet::Render(RenderWindow& window) {
	for (const auto b : bullets) {
		window.draw(b);
	}
}

void Bullet::Fire(const Vector2f& pos, const bool mode) {
	++bulletPointer;
	bullets[bulletPointer].setTexture(spritesheet);
	bullets[bulletPointer].setTextureRect(mode ? IntRect(64, 32, 32, 32) : IntRect(32, 32, 32, 32));
	bullets[bulletPointer].setOrigin(16, 16);
	bullets[bulletPointer].setPosition(pos);
}

void Bullet::_Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		return;
	}
	else {
		move(0, dt * 200.f * (_mode ? 1.f : -1.f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			if (!_mode && s->is_player()) {
				continue;
			}
			if (_mode && !s->is_player()) {
				continue;
			}
			if (!s->is_exploded() && s->getGlobalBounds().intersects(boundingBox)) {
				s->Explode();
				setPosition(-100, -100);
				return;
			}
		}
	}
}