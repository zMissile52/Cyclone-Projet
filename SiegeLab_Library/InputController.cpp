#include "InputController.h"

InputSnapshot InputController::Capture() const
{
	InputSnapshot snapshot{};
	snapshot.right_mouse_down = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
	snapshot.mouse_delta = GetMouseDelta();
	snapshot.reset_camera = IsKeyPressed(KEY_R);

	snapshot.move_left_a = IsKeyDown(KEY_A);
	snapshot.move_right_d = IsKeyDown(KEY_D);
	snapshot.pitch_up_w = IsKeyDown(KEY_W);
	snapshot.pitch_down_s = IsKeyDown(KEY_S);
	snapshot.speed_down_q = IsKeyDown(KEY_Q);
	snapshot.speed_up_e = IsKeyDown(KEY_E);

	snapshot.select_standard_1 = IsKeyPressed(KEY_ONE);
	snapshot.select_heavy_2 = IsKeyPressed(KEY_TWO);
	snapshot.fire_pressed_space = IsKeyPressed(KEY_SPACE);
	return snapshot;
}