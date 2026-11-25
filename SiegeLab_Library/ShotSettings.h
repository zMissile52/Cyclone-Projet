#pragma once
#include <cyclone/core.h>
enum ProjectileType
{
	STANDARD,
	HEAVY
};

class ShotSettings
{
public:
	cyclone::Vector3 origin;
	cyclone::Vector3 direction;
	double speed;
	ProjectileType projectileKind;
};

