#ifndef SIEGELAB_LIBRARY_STANDARDPROJECTILE_H_
#define SIEGELAB_LIBRARY_STANDARDPROJECTILE_H_

#include "Projectile.h"

class StandardProjectile : public Projectile
{
public:
	void ConfigurePhysics() override;
};

#endif