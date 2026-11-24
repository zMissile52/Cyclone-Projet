#ifndef SIEGELAB_LIBRARY_ORBITCAMERA_H_
#define SIEGELAB_LIBRARY_ORBITCAMERA_H_

#include "../Cyclone/include/cyclone/core.h"
#include "InputController.h"

using namespace cyclone;

class OrbitalCamera : public InputController
{
public:
	OrbitalCamera(Vector3 target, double radius, double rotationSpeed);

private:
	Vector3 target;
	double radius;
	double rotationSpeed;
	double yaw;
	double pitch;
};

#endif