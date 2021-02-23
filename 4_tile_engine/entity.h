#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

class Entity {
protected:
	unique_ptr<Shape> _shape;
	Vector2f _position;
	Entity(unique_ptr<Shape> ship);

public:
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(const double dt);
	virtual void Render(RenderWindow &window) const = 0;

	const Vector2f getPosition();
	void setPosition(const Vector2f& pos);
	void move(const Vector2f &pos);
};