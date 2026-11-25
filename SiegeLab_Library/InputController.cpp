#include "InputController.h"

void InputController::Update()
{
    m_right_mouse_down = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
    m_mouse_delta = ::GetMouseDelta();
    m_wheel_move = GetMouseWheelMove();
    m_yaw_axis = 0.0f;
    m_pitch_axis = 0.0f;

    if (IsKeyDown(KEY_RIGHT)) m_yaw_axis += 1.0f;
    if (IsKeyDown(KEY_LEFT)) m_yaw_axis -= 1.0f;
    if (IsKeyDown(KEY_UP)) m_pitch_axis += 1.0f;
    if (IsKeyDown(KEY_DOWN)) m_pitch_axis -= 1.0f;
}

bool InputController::IsRightMouseDown() const { return m_right_mouse_down; }
Vector2 InputController::GetMouseDelta() const { return m_mouse_delta; }
float InputController::GetYawAxis() const { return m_yaw_axis; }
float InputController::GetPitchAxis() const { return m_pitch_axis; }
float InputController::GetZoomAxis() const { return m_zoom_axis; }
