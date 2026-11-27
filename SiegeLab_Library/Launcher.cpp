#include "Launcher.h"

#include <algorithm>
#include <cmath>

#include "raylib.h"

namespace
{

    constexpr double kMinYawDeg = -30.0;
    constexpr double kMaxYawDeg = 30.0;
    constexpr double kMinPitchDeg = 5.0;
    constexpr double kMaxPitchDeg = 55.0;
    constexpr double kMinSpeedMps = 8.0;
    constexpr double kMaxSpeedMps = 22.0;
    constexpr double kSpeedAdjustRate = 10.0;

}  // namespace

void Launcher::Aim(const InputSnapshot& _input, float _dt)
{
    UpdateAnglesAndSpeed(_input, _dt);
    UpdateDirection();
    m_shot_settings.speed = m_speed_mps;
}

void Launcher::UpdateAnglesAndSpeed(const InputSnapshot& _input, float _dt)
{
    const double step_deg = static_cast<double>(_dt) * m_turn_rate_deg_per_sec;
    const double step_spd = static_cast<double>(_dt) * kSpeedAdjustRate;

    if (_input.move_left_a)
    {
        m_yaw_deg = std::clamp(m_yaw_deg - step_deg, kMinYawDeg, kMaxYawDeg);
    }
    if (_input.move_right_d)
    {
        m_yaw_deg = std::clamp(m_yaw_deg + step_deg, kMinYawDeg, kMaxYawDeg);
    }
    if (_input.pitch_up_w)
    {
        m_pitch_deg = std::clamp(m_pitch_deg + step_deg, kMinPitchDeg, kMaxPitchDeg);
    }
    if (_input.pitch_down_s)
    {
        m_pitch_deg = std::clamp(m_pitch_deg - step_deg, kMinPitchDeg, kMaxPitchDeg);
    }
    if (_input.speed_down_q)
    {
        m_speed_mps = std::clamp(m_speed_mps - step_spd, kMinSpeedMps, kMaxSpeedMps);
    }
    if (_input.speed_up_e)
    {
        m_speed_mps = std::clamp(m_speed_mps + step_spd, kMinSpeedMps, kMaxSpeedMps);
    }
    if (_input.select_standard_1)
    {
        m_shot_settings.projectile_kind = ProjectileKind::kStandard;
    }
    if (_input.select_heavy_2)
    {
        m_shot_settings.projectile_kind = ProjectileKind::kHeavy;
    }
}

void Launcher::UpdateDirection()
{
    const double yaw_rad = m_yaw_deg * DEG2RAD;
    const double pitch_rad = m_pitch_deg * DEG2RAD;
    const double cos_pitch = std::cos(pitch_rad);

    cyclone::Vector3 dir(
        cos_pitch * std::cos(yaw_rad),
        std::sin(pitch_rad),
        cos_pitch * std::sin(yaw_rad));
    if (dir.squareMagnitude() > 0.0)
    {
        dir.normalise();
    }
    m_shot_settings.direction = dir;
}