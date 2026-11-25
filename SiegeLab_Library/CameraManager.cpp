#include "CameraManager.h"

void CameraManager::SetActive(ICameraController* _controller)
{
	m_current_camera = _controller;
}

ICameraController* CameraManager::GetActive() const
{
	return m_current_camera;
}

void CameraManager::update(const InputSnapshot& _input, float _dt)
{
	if (m_current_camera != nullptr) {
		m_current_camera->update(_input, _dt);
	}
}

Camera3D CameraManager::getCamera() const
{
	if (m_current_camera != nullptr) {
		m_current_camera->getCamera();
	}
	Camera3D fallback = { 0 };
	fallback.position = {0.0f, 3.0f, 0.0f};
	fallback.target = {0.0f, 1.0f, 0.0f};
	fallback.up = { 0.0f, 1.0f, 0.0f };
	fallback.fovy = 45.0f;
	fallback.projection = CAMERA_PERSPECTIVE;

	return fallback;
}

void CameraManager::reset()
{
	if (m_current_camera != nullptr)
	{
		m_current_camera->reset();
	}
}
