#ifndef SIEGELAB_LIBRARY_SHOTSETTINGS_H_
#define SIEGELAB_LIBRARY_SHOTSETTINGS_H_

#include <cyclone/core.h>

enum class ProjectileKind
{
	kStandard,
	kHeavy,
};

struct ShotSettings
{
	cyclone::Vector3 origin{ 0.0, 0.0, 0.0 };
	cyclone::Vector3 direction{ 1.0, 0.0, 0.0 };
	double speed = 8.0;
	ProjectileKind projectile_kind = ProjectileKind::kStandard;
};

#endif