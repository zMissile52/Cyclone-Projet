#ifndef SIEGELAB_LIBRARY_ORBITCAMERA_H_
#define SIEGELAB_LIBRARY_ORBITCAMERA_H_

#include "InputController.h"
#include "raylib.h"

class OrbitalCamera : public InputController
{
public:
	void update(const InputController& input, double dt);

private:
	Vector3 target;
	double radius;
	double rotationSpeed;
	double yaw = 0.0f;
	double pitch = 0.0f;
};

#endif