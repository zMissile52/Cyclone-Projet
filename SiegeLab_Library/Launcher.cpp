#include "Launcher.h"

#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "raymath.h"

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
    const double step_speed = static_cast<double>(_dt) * kSpeedAdjustRate;

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
        m_speed_mps = std::clamp(m_speed_mps - step_speed, kMinSpeedMps, kMaxSpeedMps);
    }
    if (_input.speed_up_e)
    {
        m_speed_mps = std::clamp(m_speed_mps + step_speed, kMinSpeedMps, kMaxSpeedMps);
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
    const float yaw_rad = static_cast<float>(-m_yaw_deg * DEG2RAD);
    const float pitch_rad = static_cast<float>(m_pitch_deg * DEG2RAD);

    const Vector3 initial_direction{ 1.0f, 0.0f, 0.0f };
    const Matrix rotation = MatrixMultiply(
        MatrixRotateZ(pitch_rad),
        MatrixRotateY(yaw_rad));
    const Vector3 rotated_direction = Vector3Transform(initial_direction, rotation);

    cyclone::Vector3 direction(
        rotated_direction.x,
        rotated_direction.y,
        rotated_direction.z);
    if (direction.squareMagnitude() > 0.0)
    {
        direction.normalise();
    }
    m_shot_settings.direction = direction;
}

void Launcher::Draw() const
{
    const ::Vector3 start_point{ -8.0f, 1.0f, 0.0f };
    const cyclone::Vector3& direction = m_shot_settings.direction;
    constexpr float line_length = 10.0f;
    const ::Vector3 end_point{
        start_point.x + static_cast<float>(direction.x) * line_length,
        start_point.y + static_cast<float>(direction.y) * line_length,
        start_point.z + static_cast<float>(direction.z) * line_length
    };

    DrawLine3D(start_point, end_point, RED);
    DrawCube(start_point, 0.5f, 1.5f, 0.5f, BLUE);
}