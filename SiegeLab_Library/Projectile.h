#pragma once
#include "GameEntity.h"
#include "SceneObjects.h"
#include <cyclone/particle.h>

struct Settings {

};

class Projectile : public GameEntity
{
public:
	virtual void fire(Settings _set) {};

	virtual void draw() const = 0;

	virtual void registerPhysics(SceneObjects _world) {};
protected:
	//TODO CollisionSphere
	cyclone::Particle p;

	double mass = 0;
	double radius = 1;
};

