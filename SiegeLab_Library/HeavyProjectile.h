#ifndef SIEGELAB_LIBRARY_HEAVYPROJECTILE_H_
#define SIEGELAB_LIBRARY_HEAVYPROJECTILE_H_

#include "Projectile.h"

class HeavyProjectile : public Projectile
{
public:
	void ConfigurePhysics() override;
};

#endif