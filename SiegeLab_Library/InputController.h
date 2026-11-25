#ifndef SIEGELAB_LIBRARY_INPUTCONTROLLER_H_
#define SIEGELAB_LIBRARY_INPUTCONTROLLER_H_

#include "raylib.h"

class InputController
{
public:
	void Update();
	bool    IsRightMouseDown() const;
	Vector2 GetMouseDelta() const;
	float   GetWheelMove() const;
	float   GetYawAxis() const;
	float   GetPitchAxis() const;
	float   GetZoomAxis() const;

private:
	bool    m_right_mouse_down = false;
	Vector2 m_mouse_delta{ 0.0f, 0.0f };
	float   m_wheel_move = 0.0f;
	float   m_yaw_axis = 0.0f;
	float   m_pitch_axis = 0.0f;
	float   m_zoom_axis = 0.0f;
};

#endif