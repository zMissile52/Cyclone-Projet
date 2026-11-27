#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

struct InputSnapshot
{
	bool    right_mouse_down = false;
	Vector2 mouse_delta{ 0.0f, 0.0f };
	bool    reset_camera = false;

	bool    move_left_a = false;
	bool    move_right_d = false;
	bool    pitch_up_w = false;
	bool    pitch_down_s = false;
	bool    speed_down_q = false;
	bool    speed_up_e = false;

	bool    select_standard_1 = false;
	bool    select_heavy_2 = false;
	bool    fire_pressed_space = false;
};

class InputController
{
public:
	InputSnapshot Capture() const;
};

#endif