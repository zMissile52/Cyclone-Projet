#ifndef SIEGELAB_LIBRARY_CAMERAMANAGER_H_
#define SIEGELAB_LIBRARY_CAMERAMANAGER_H_

#include "ICameraController.h"

class CameraManager : public ICameraController
{
public:
	void update(const InputSnapshot& _controller, float _dt) override;
	Camera3D getCamera() override;
	void reset() override;

private:
	ICameraController* m_currentCamera = nullptr;
};

#endif