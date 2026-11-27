#pragma once
#include "ShotSettings.h"
#include "InputController.h"

class Launcher
{
	friend class LauncherTest;
private:
	double yaw = 0;  //{-30, 30}; // horizontal // azimuth
	double pitch = 5;  //{5, 55}; // vertical // elevation
	double speed = 8;  //{8, 22}; // en m/s
	double speed_orient = 100;
	ShotSettings shotSets;

public:
	void aim(const InputSnapshot _settings, float _dt);
	cyclone::Vector3 CalculDir();
	void draw(InputSnapshot _i, float _dt);
	ShotSettings& shotSettings();
	cyclone::Vector3 previousDir;
};

