#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

struct InputController 
{
	bool rmbDown = false;
	Vector2 mouseDelta = { 0.0f, 0.0f };
	float mouseWheel = 0.0f;
	float yawAxis = 0.0f;
	float pitchAxis = 0.0f;
};

#endif