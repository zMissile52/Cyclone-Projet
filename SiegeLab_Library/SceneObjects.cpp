#include "SceneObjects.h"

SceneObjects::~SceneObjects()
{

}

GameEntity* SceneObjects::get(EntityId id)
{
    return gameObjects.Get(id);
}

void SceneObjects::flushRemovals()
{

}
