#ifndef SIEGELAB_LIBRARY_SCENEOBJECTS_H_
#define SIEGELAB_LIBRARY_SCENEOBJECTS_H_

#include <iostream>
#include "EntityId.h"
#include "GameEntity.h"
#include "ObjectPool.h"

class SceneObjects
{
public:
	SceneObjects() = default;
	~SceneObjects();

	template<typename T, typename... Args>
		requires std::derived_from<T, GameEntity> && (!std::is_abstract_v<T>)
	EntityId createEntity(Args&&... args);
	

	GameEntity* get(EntityId id);
	void flushRemovals();

private:
	ObjectPool<GameEntity*, 20> gameObjects;
};

#endif

#include "SceneObjects.inl"