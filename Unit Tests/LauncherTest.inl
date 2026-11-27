#pragma once

#include <cmath>

class LauncherTest : public ::testing::Test
{
protected:
    static constexpr double kTolerance = 1e-4;

    static void AimAt(Launcher& _launcher,
        double _azimuth_deg,
        double _elevation_deg,
        double _speed_mps)
    {
        InputSnapshot input{};

        if (_azimuth_deg != 0.0)
        {
            input.move_right_d = _azimuth_deg > 0.0;
            input.move_left_a = _azimuth_deg < 0.0;
            _launcher.Aim(input, static_cast<float>(std::abs(_azimuth_deg) / 90.0));
            input = {};
        }

        const double elevation_delta = _elevation_deg - 5.0;
        if (elevation_delta != 0.0)
        {
            input.pitch_up_w = elevation_delta > 0.0;
            input.pitch_down_s = elevation_delta < 0.0;
            _launcher.Aim(input, static_cast<float>(std::abs(elevation_delta) / 90.0));
            input = {};
        }

        const double speed_delta = _speed_mps - 8.0;
        if (speed_delta != 0.0)
        {
            input.speed_up_e = speed_delta > 0.0;
            input.speed_down_q = speed_delta < 0.0;
            _launcher.Aim(input, static_cast<float>(std::abs(speed_delta) / 10.0));
        }
        else
        {
            _launcher.Aim(input, 0.0f);
        }
    }

    static cyclone::Vector3 ExpectedDirection(double _azimuth_deg,
        double _elevation_deg)
    {
        const double azimuth = _azimuth_deg * DEG2RAD;
        const double elevation = _elevation_deg * DEG2RAD;
        return cyclone::Vector3(
            std::cos(elevation) * std::cos(azimuth),
            std::sin(elevation),
            std::cos(elevation) * std::sin(azimuth));
    }

    static bool Ecart(const cyclone::Vector3& _actual,
        const cyclone::Vector3& _expected)
    {
        return std::abs(_actual.x - _expected.x) <= kTolerance
            && std::abs(_actual.y - _expected.y) <= kTolerance
            && std::abs(_actual.z - _expected.z) <= kTolerance;
    }
};