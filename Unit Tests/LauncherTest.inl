#pragma once
class LauncherTest : public::testing::Test {
public:
	double Get_Azimuth(Launcher l) { return l.yaw; };
	double Get_Elevation(Launcher l) { return l.pitch; };
	void Set_Azimuth(Launcher& l, double a) { l.yaw = a; };
	void Set_Elevation(Launcher& l, double e) { l.pitch = e; };

	bool Ecart(cyclone::Vector3 v1, cyclone::Vector3 v2, double ecart) {
		cyclone::Vector3 result = v1 - v2;
		result = {
			real_abs(result.x),
			real_abs(result.y),
			real_abs(result.z) };
		return result.x <= ecart && result.y <= ecart && result.z <= ecart;
	}

};

