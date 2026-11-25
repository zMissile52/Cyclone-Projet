#include "InputController.h"

InputSnapshot InputController::capture() const
{
	InputSnapshot snapshot;
	snapshot.right_mouse_down = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
	snapshot.mouse_delta = GetMouseDelta();
	snapshot.reset_camera = IsKeyPressed(KEY_R);


	snapshot.isPressedA = IsKeyPressed(KEY_A);
	snapshot.isPressedD = IsKeyPressed(KEY_D);

	snapshot.isPressedW = IsKeyPressed(KEY_W);
	snapshot.isPressedS = IsKeyPressed(KEY_S);

	snapshot.isPressedQ = IsKeyPressed(KEY_Q);
	snapshot.isPressedE = IsKeyPressed(KEY_E);


	snapshot.isPressed1 = IsKeyPressed(KEY_ONE);
	snapshot.isPressed2 = IsKeyPressed(KEY_TWO);

	

	return snapshot;
}
