#pragma once
template<typename T, typename ...Args>
	requires std::derived_from<T, GameEntity> && (!std::is_abstract_v<T>)
inline EntityId SceneObjects::createEntity(Args && ...args)
{
	return gameObjects.Create(T(args...));
}