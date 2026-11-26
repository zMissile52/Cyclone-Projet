#include "InputController.h"

InputSnapshot InputController::capture() const
{
	InputSnapshot snapshot;
	snapshot.right_mouse_down = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
	snapshot.mouse_delta = GetMouseDelta();
	snapshot.reset_camera = IsKeyPressed(KEY_R);


	snapshot.isPressedA = IsKeyDown(KEY_A);
	snapshot.isPressedD = IsKeyDown(KEY_D);

	snapshot.isPressedW = IsKeyDown(KEY_W);
	snapshot.isPressedS = IsKeyDown(KEY_S);

	snapshot.isPressedQ = IsKeyDown(KEY_Q);
	snapshot.isPressedE = IsKeyDown(KEY_E);


	snapshot.isPressed1 = IsKeyDown(KEY_ONE);
	snapshot.isPressed2 = IsKeyDown(KEY_TWO);

	snapshot.add_speed_orient = IsKeyPressed(KEY_P);
	snapshot.remove_speed_orient = IsKeyPressed(KEY_O);

	return snapshot;
}
