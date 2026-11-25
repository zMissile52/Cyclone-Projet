#pragma once
#include "ShotSettings.h"
class Launcher
{
private:
	double yaw[2] = {-30, 30}; //vertical
	double pitch[2] = {5, 55}; //horizontal
	double speed[2] = {8, 22}; // en m/s
	ShotSettings shotSets;
public:
	void aim();
	ShotSettings& shotSettings();
};

