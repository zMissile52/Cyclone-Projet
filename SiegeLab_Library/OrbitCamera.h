#ifndef SIEGELAB_LIBRARY_ORBITCAMERA_H_
#define SIEGELAB_LIBRARY_ORBITCAMERA_H_

#include "raylib.h"
#include "ICameraController.h"
#include "InputController.h"

class OrbitCamera : public ICameraController
{
	friend class OrbitCameraTest;
public:
	void update(const InputSnapshot& _input, float _dt) override;
	Camera3D getCamera() override;
	void reset() override;

private:
	Vector3 m_initial_target{ 0.0f, 1.0f, 0.0f };
	Vector3 m_initial_position{ 0.0f, 3.0f, 10.0f };
	float m_intial_distance = 10.0f;
	float m_initial_yaw = 0.0f;
	float m_initial_pitch = 0.0f;
	Vector3 m_position{ 0.0f, 3.0f, 10.0f };
	Vector3 m_target{ 0.0f, 1.0f, 0.0f };
	float m_yaw = 0.0f;
	float m_pitch = 0.0f;
	float m_distance = 10.0f;
	float m_degrees_per_pixel = 0.25f;
};

#endif