#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

struct InputSnapshot
{
	bool    right_mouse_down = false;
	Vector2 mouse_delta{ 0.0f, 0.0f };
	bool reset_camera = false;

	// azimuth
	bool isPressedA = false;
	bool isPressedD = false;

	// elevation
	bool isPressedW = false;
	bool isPressedS = false;

	// speed
	bool isPressedQ = false;
	bool isPressedE = false;

	//projectile select
	bool isPressed1 = false;
	bool isPressed2 = false;

	// change orientaiton speed
	bool add_speed_orient;
	bool remove_speed_orient;

};

class InputController
{
public:
	InputSnapshot capture() const;
};

#endif