#ifndef SIEGELAB_LIBRARY_ORBITCAMERA_H_
#define SIEGELAB_LIBRARY_ORBITCAMERA_H_

#include "raylib.h"
#include "ICameraController.h"
#include "InputController.h"

class OrbitCamera : public ICameraController
{
public:
	void update(const InputSnapshot& _input, float _dt) override;
	Camera3D getCamera() override;
	void reset() override;

private:
	Vector3 m_position{ 0.0f, 4.0f, 12.0f };
	Vector3 m_target{ 0.0f, 1.0f, 0.0f };
	float m_yaw = 0.0f;
	float m_pitch = 0.0f;
	float m_distance = 12.0f;
};

#endif