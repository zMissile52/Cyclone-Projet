#ifndef SIEGELAB_LIBRARY_PROJECTILE_H_
#define SIEGELAB_LIBRARY_PROJECTILE_H_

#include <cyclone/collide_fine.h>
#include <cyclone/core.h>
#include <cyclone/precision.h>

#include "GameEntity.h"
#include "SceneObjects.h"
#include "ShotSettings.h"

class Projectile : public GameEntity
{
public:
    void Fire(const ShotSettings& _settings);
    void Draw() const override;
    void RegisterPhysics(SceneObjects& _world) override;
    virtual void ConfigurePhysics() = 0;
    void ConfigureSphereBody(cyclone::real _mass,
                             cyclone::real _radius);

    const cyclone::CollisionSphere& GetSphere() const { return m_sphere; }
    cyclone::CollisionSphere& MutableSphere() { return m_sphere; }

private:
    cyclone::CollisionSphere m_sphere{};
};

#endif