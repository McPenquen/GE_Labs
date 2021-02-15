#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Ship parent
class Ship : public Sprite {
protected:
	IntRect _sprite;
	// Default constructor
	Ship();
	bool _exploded = false;
	bool _player = false;
public:
	// Constructor with a sprite
	explicit Ship(IntRect ir);
	// Virtual decontructor (pure - it has to be overriden)
	virtual ~Ship() = 0;
	// Virtual update
	virtual void Update(const float& dt);
	// Virtual Move down
	virtual void moveDown();
	bool is_exploded() const;
	virtual void Explode();
	virtual bool is_player() const;
};

// Invader
class Invader : public Ship {
public:
	Invader(IntRect ir, Vector2f pos);
	Invader();
	void Update(const float &dt) override;
	static bool direction;
	static float speed;
	void moveDown() override;
};

// Player
class Player : public Ship {
protected:
	bool _player = true;
public:
	Player();
	void Update(const float &dt) override;
};
