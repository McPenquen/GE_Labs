#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "lib_ecm.h"

using namespace sf;
using namespace std;
/*
class Entity {
protected:
	unique_ptr<Shape> _shape;
	Vector2f _position;
	Entity(unique_ptr<Shape> shape);

public:
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(double dt);
	virtual void Render() const = 0;

	const Vector2f getPosition();
	void setPosition(const Vector2f& pos);
	void move(const Vector2f& pos);
};
*/
class Player : public Entity {
private:
	float _speed;
public:
	Player();
	void Update(double dt) override;
	void Render() override;
};

class Ghost : public Entity {
private:
	static float _speed;
	float directionChangeTime = 0.f;
	Vector2f movementDirection;
public:
	Ghost();
	Ghost(Vector2f new_pos);
	//void Update(double dt) override;
	//void Render() override;
};

struct EntityManager {
	vector<shared_ptr<Entity>> list;
	void Update(double dt);
	void Render();
};