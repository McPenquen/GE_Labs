#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>

using namespace std;
using namespace sf;

class Component;

class Entity {
protected:
	vector<shared_ptr<Component>> _components;
	Vector2f _position;
	float _rotation;
	bool _alive; // should be update
	bool _visible; // should be rendered
	bool _fordeletion = false; //should be deleted

public:
	Entity();
	virtual ~Entity();
	virtual void Update(double dt);
	virtual void Render();

	const Vector2f& getPosition() const;
	void setPosition(const Vector2f& new_position);
	float getRotation() const;
	void setRotation(float new_rotation);
	bool isAlive() const;
	void setAlive(bool new_alive);
	bool isVisible() const;
	void setVisible(bool new_visible);
	bool is_fordeletion() const;
	void setForDelete();

	template <typename T, typename... Targs>
	shared_ptr<T> addComponent(Targs... params) {
		static_assert(is_base_of<Component, T>::value, "T != component");
		shared_ptr<T> sp(make_shared<T>(this, params...));
		_components.push_back(sp);
		return sp;
	}
};

class Component {
protected:
	Entity* const _parent;
	bool _fordeletion = false;
	explicit Component(Entity* const p);

public:
	Component();
	bool is_fordeletion() const;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Component();
};
