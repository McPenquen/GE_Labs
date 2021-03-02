#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Renderer {
	void intialise(RenderWindow&);
	RenderWindow& getWindow();

	void shutdown();
	void update(const double &);
	void queue(const Drawable* s);
	void render();
};