#pragma once
#include "ShotSettings.h"
#include "InputController.h"

class Launcher
{
private:
	
	double yaw = 0;  //{-30, 30}; //vertical
	double pitch = 5;  //{5, 55}; //horizontal
	double speed = 8;  //{8, 22}; // en m/s
	ShotSettings shotSets;

public:
	void aim(const InputSnapshot _settings, float _dt);
	ShotSettings& shotSettings();
};

