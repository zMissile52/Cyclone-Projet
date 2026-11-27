#pragma once
class LauncherTest : public::testing::Test {
public:
	double Get_Azimuth(Launcher _l) { return _l.yaw; };
	double Get_Elevation(Launcher _l) { return _l.pitch; };
	double Get_Speed(Launcher _l) { return _l.speed; };
	void Set_Azimuth(Launcher& _l, double _a) { _l.yaw = _a; };
	void Set_Elevation(Launcher& _l, double _e) { _l.pitch = _e; };
	void Set_Speed(Launcher& _l, double _s) { _l.speed = _s; };

	bool Ecart(cyclone::Vector3 _v1, cyclone::Vector3 _v2, double _ecart) {
		cyclone::Vector3 a = 
		{
		real_abs(_v1.x),
		real_abs(_v1.y),
		real_abs(_v1.z) 
		};

		cyclone::Vector3 b = 
		{
		real_abs(_v2.x),
		real_abs(_v2.y),
		real_abs(_v2.z) 
		};

		cyclone::Vector3 result = a - b;
		result = {
		real_abs(result.x),
		real_abs(result.y),
		real_abs(result.z)
		};
		return result.x <= _ecart 
			&& result.y <= _ecart 
			&& result.z <= _ecart;
	}

};

