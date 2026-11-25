#include "OrbitCamera.h"
#include "raymath.h"
#include <algorithm>

void OrbitCamera::update(const InputSnapshot& _input, float _dt)
{
    if (_input.reset_camera)
    {
        reset();
        return;
    }

    if (_input.right_mouse_down) {
        m_yaw += _input.mouse_delta.x * m_degrees_per_pixel;
        m_pitch -= _input.mouse_delta.y * m_degrees_per_pixel;
        m_pitch = std::clamp(m_pitch, 0.0f, 90.0f);
    }

    const float yaw_rad = m_yaw * DEG2RAD;
    const float pitch_rad = m_pitch * DEG2RAD;
    Vector3 offset{ 0.0f, 0.0f, m_distance };
    offset = Vector3Transform(offset, MatrixRotateX(-pitch_rad));
    offset = Vector3Transform(offset, MatrixRotateY(yaw_rad));
    m_position = Vector3Add(m_target, offset);
}

Camera3D OrbitCamera::getCamera()
{
    Camera3D camera = { 0 };
    camera.position = m_position; 
    camera.target = m_target;
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}

void OrbitCamera::reset()
{
    m_target = m_initial_target;
    m_distance = m_intial_distance;
    m_yaw = m_initial_yaw;
    m_pitch = m_initial_pitch;

    const float yaw_rad = m_yaw * DEG2RAD;
    const float pitch_rad = m_pitch * DEG2RAD;
    Vector3 offset{ 0.0f, 0.0f, m_distance };
    offset = Vector3Transform(offset, MatrixRotateX(-pitch_rad));
    offset = Vector3Transform(offset, MatrixRotateY(yaw_rad));
    m_position = Vector3Add(m_target, offset);
}
