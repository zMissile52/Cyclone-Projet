#include "InputController.h"

InputSnapshot InputController::capture() const
{
	InputSnapshot snapshot;
	snapshot.key_a = false;
	snapshot.key_b = false;

	return snapshot;
}
