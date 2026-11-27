#pragma once
class OrbitCameraTest : public::testing::Test {
	void Set_Yaw(OrbitCamera _cam, float _y) { _cam.m_yaw = _y; };
	float Get_Yaw(OrbitCamera _cam, float _y) { _cam.m_yaw = _y; };
};