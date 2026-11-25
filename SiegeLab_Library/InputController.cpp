#include "InputController.h"

InputSnapshot InputController::capture() const
{
	InputSnapshot snapshot;
	snapshot.right_mouse_down = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
	snapshot.mouse_delta = GetMouseDelta();
	snapshot.reset_camera = IsKeyPressed(KEY_R);

	return snapshot;
}
