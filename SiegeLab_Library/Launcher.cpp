#include "Launcher.h"
#include <algorithm>

void Launcher::aim(const InputSnapshot _settings, float _dt)
{

    double budget = _dt * 0.25;//TODO mettre le multiplicateur speed * dt
    
    // azimuth
    if (_settings.isPressedA) {
        yaw = std::clamp<double>(yaw - budget, -30.0, 30.0); 
    }
    if (_settings.isPressedD) {
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
}

ShotSettings& Launcher::shotSettings()
{
    shotSets.direction = { 1, 0, 0 };
    

    return shotSets;
}
