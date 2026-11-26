#include "Launcher.h"
#include <algorithm>
#include <cmath>
#include <iostream>

void Launcher::aim(const InputSnapshot _settings, float _dt)
{

    double budget = _dt * speed_orient;//TODO mettre le multiplicateur speed * dt
    
    // azimuth
    if (_settings.isPressedD) {
        yaw = std::clamp<double>(yaw - budget, -30.0, 30.0); 
    }
    if (_settings.isPressedA) {
        yaw = std::clamp<double>(yaw + budget, -30.0, 30.0);
    }

    // elevation
    if (_settings.isPressedS) {
        pitch = std::clamp<double>(pitch - budget, 5.0, 55.0);
    }
    if (_settings.isPressedW) {
        pitch = std::clamp<double>(pitch + budget, 5.0, 55.0);
    }

    // speed
    if (_settings.isPressedQ) {
        speed = std::clamp<double>(speed - budget, 8.0, 22.0);
    }
    if (_settings.isPressedE) {
        speed = std::clamp<double>(speed + budget, 8.0, 22.0);
    }

    // weapon change
    if (_settings.isPressed1) {
        shotSets.projectileKind = ProjectileType::STANDARD;
    }
    if (_settings.isPressed2) {
        shotSets.projectileKind = ProjectileType::HEAVY;
    }

    // speed orientation
    double step = 20;
    if (_settings.add_speed_orient) {
        speed_orient = std::clamp<double>(speed_orient + step, 20.0, 100.0);
    }
    if (_settings.remove_speed_orient) {
        speed_orient = std::clamp<double>(speed_orient - step, 20.0, 100.0);
    }


    double rotaPitch = pitch * DEG2RAD; // en radian
    double rotaYaw = yaw * DEG2RAD;

    previousDir = shotSets.direction;

    shotSets.direction.x = std::sin(rotaYaw) * std::cos(rotaPitch);
    shotSets.direction.y = -std::sin(rotaPitch);
    shotSets.direction.z = std::cos(rotaYaw) * std::cos(rotaPitch);

    if (previousDir != shotSets.direction) {
        std::cout << "direction : "
            << shotSets.direction.x
            << ", "
            << shotSets.direction.y
            << ", "
            << shotSets.direction.z
            << std::endl;

        std::cout << "speed_orient : " << speed_orient<< std::endl;
    }
    
}

ShotSettings& Launcher::shotSettings()
{
    
    return shotSets;
}
