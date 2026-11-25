#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

struct InputSnapshot
{
	bool    right_mouse_down = false;
	Vector2 mouse_delta{ 0.0f, 0.0f };
	bool reset_camera = false;
};

class InputController
{
public:
	InputSnapshot capture() const;
};

#endif