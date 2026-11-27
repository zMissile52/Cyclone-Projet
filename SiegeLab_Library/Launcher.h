#ifndef SIEGELAB_LIBRARY_LAUNCHER_H_
#define SIEGELAB_LIBRARY_LAUNCHER_H_

#include <cyclone/core.h>

#include "InputController.h"
#include "ShotSettings.h"

class Launcher
{
public:
    void Aim(const InputSnapshot& _input, float _dt);
    void Draw() const;

    const ShotSettings& GetShotSettings() const { return m_shot_settings; }
    ShotSettings& MutableShotSettings() { return m_shot_settings; }

private:
    void UpdateAnglesAndSpeed(const InputSnapshot& _input, float _dt);
    void UpdateDirection();

    double m_yaw_deg = 0.0;
    double m_pitch_deg = 5.0;
    double m_speed_mps = 8.0;
    double m_turn_rate_deg_per_sec = 90.0;
    ShotSettings m_shot_settings{};
};

#endif