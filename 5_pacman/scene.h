#pragma once
#include "entity.h"

using namespace std;

class Scene {
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void Update(double dt);
	virtual void Render();
	virtual void Load() = 0;
	vector<shared_ptr<Entity>>&getEnts();

protected:
	EntityManager _ents;
};