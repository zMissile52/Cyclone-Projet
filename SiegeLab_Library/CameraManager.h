#ifndef SIEGELAB_LIBRARY_CAMERAMANAGER_H_
#define SIEGELAB_LIBRARY_CAMERAMANAGER_H_

#include "ICameraController.h"
#include "InputController.h"
#include "raylib.h"

class CameraManager
{
public:
	void SetActive(ICameraController* _controller);
	ICameraController* GetActive() const;
	void update(const InputSnapshot& _input, float _dt);
	Camera3D getCamera() const;
	void reset();

private:
	ICameraController* m_current_camera = nullptr;
};

#endif