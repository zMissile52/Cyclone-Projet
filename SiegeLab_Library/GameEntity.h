#ifndef SIEGELAB_LIBRARY_GAMEENTITY_H_
#define SIEGELAB_LIBRARY_GAMEENTITY_H_

class GameEntity
{
	virtual ~GameEntity() = default;
	virtual void draw() const = 0;
};

#endif