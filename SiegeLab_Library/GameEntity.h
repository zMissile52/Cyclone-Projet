#ifndef SIEGELAB_LIBRARY_GAMEENTITY_H_
#define SIEGELAB_LIBRARY_GAMEENTITY_H_

struct RigidBody {
	// TODO voir qu'est ce que c'est sensé etre
};


class GameEntity
{
public:
	virtual ~GameEntity() = default;
	virtual void draw() const = 0;
private:
	RigidBody body;
};

#endif