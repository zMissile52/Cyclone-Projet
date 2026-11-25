#ifndef SIEGELAB_LIBRARY_GAMEENTITY_H_
#define SIEGELAB_LIBRARY_GAMEENTITY_H_

#include <cyclone/body.h>

class GameEntity
{
public:
	virtual ~GameEntity() = default;
	virtual void draw() const = 0;
	virtual void registerPhysics(SceneObjects& _world) = 0;

	cyclone::RigidBody getBody() { return m_body; }

private:
	cyclone::RigidBody m_body;
};

#endif