#pragma once
#include "ShotSettings.h"
#include "InputController.h"

class Launcher
{
private:
	
	double yaw = 0;  //{-30, 30}; // horizontal
	double pitch = 5;  //{5, 55}; // vertical
	double speed = 8;  //{8, 22}; // en m/s
	double speed_orient = 100;
	ShotSettings shotSets;

public:
	void aim(const InputSnapshot _settings, float _dt);
	ShotSettings& shotSettings();
	cyclone::Vector3 previousDir;
};

