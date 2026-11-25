#include "OrbitCamera.h"

void OrbitCamera::update(const InputSnapshot& _input, float _dt)
{
    if ()
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
}
