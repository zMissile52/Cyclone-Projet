#ifndef SIEGELAB_LIBRARY_GAMEENTITY_H_
#define SIEGELAB_LIBRARY_GAMEENTITY_H_

#include <cyclone/body.h>

class SceneObjects;

class GameEntity
{
public:
	virtual ~GameEntity() = default;
	virtual void draw() const = 0;
	virtual void registerPhysics(SceneObjects& _world) = 0;

	const cyclone::RigidBody& GetBody() const { return m_body; }
	cyclone::RigidBody& Body() { return m_body; }

private:
	cyclone::RigidBody m_body;
};

#endif