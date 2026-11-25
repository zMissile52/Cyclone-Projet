#ifndef SIEGELAB_LIBRARY_ICAMERACONTROLLER_H_
#define SIEGELAB_LIBRARY_ICAMERACONTROLLER_H_

#include "raylib.h"
#include "InputController.h"

class ICameraController
{
public:
	virtual ~ICameraController() = default;

	virtual void update(const InputSnapshot& _input, float _dt) = 0;
	virtual Camera3D getCamera() = 0;
	virtual void reset() = 0;
};

#endif