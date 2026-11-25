#ifndef SIEGELAB_LIBRARY_PROJECTILE_H_
#define SIEGELAB_LIBRARY_PROJECTILE_H_

#include "GameEntity.h"
#include "SceneObjects.h"
#include <cyclone/collide_fine.h>

class Projectile : public GameEntity
{
public:
	void fire(cyclone::CollisionSphere _settings);
	void draw()const override;
	void registerPhysics(SceneObjects& _world) override;

	cyclone::CollisionSphere getSphere() { return m_sphere; }

	virtual void configurePhysics() = 0;

private:
	cyclone::CollisionSphere m_sphere;
};

#endif