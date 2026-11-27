#ifndef SIEGELAB_LIBRARY_PROJECTILE_H_
#define SIEGELAB_LIBRARY_PROJECTILE_H_

#include "GameEntity.h"
#include "SceneObjects.h"
#include "ShotSettings.h"
#include <cyclone/collide_fine.h>

class Projectile : public GameEntity
{
public:
	void fire(const ShotSettings& _settings);
	void draw()const override;
	void registerPhysics(SceneObjects& _world) override;
	virtual void configurePhysics() = 0;

	const cyclone::CollisionSphere& GetSphere() { return m_sphere; }
	cyclone::CollisionSphere& Sphere() { return m_sphere; }
	void ConfigureSphereBody(cyclone::real _mass,
							cyclone::real _radius);

private:
	cyclone::CollisionSphere m_sphere;
};

#endif