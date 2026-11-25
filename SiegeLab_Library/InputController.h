#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

struct InputSnapshot
{
	bool key_a = false;
	bool key_b = false;
};

class InputController
{
public:
	InputSnapshot capture() const;
};

#endif