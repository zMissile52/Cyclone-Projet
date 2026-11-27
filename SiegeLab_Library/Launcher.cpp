#include "Launcher.h"
#include <algorithm>
#include <iostream>
#include "raymath.h"

void Launcher::aim(const InputSnapshot _settings, float _dt)
{

    double budget = _dt * speed_orient;//TODO mettre le multiplicateur speed * dt
    
    // azimuth
    if (_settings.isPressedD) {
        yaw = yaw - budget; 
    }
    if (_settings.isPressedA) {
        yaw = yaw + budget;
    }

    // elevation
    if (_settings.isPressedS) {
        pitch = pitch - budget;
    }
    if (_settings.isPressedW) {
        pitch = pitch + budget;
    }

    // speed
    if (_settings.isPressedQ) {
        speed = speed - budget;
    }
    if (_settings.isPressedE) {
        speed = speed + budget;
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
        speed_orient = speed_orient + step;
    }
    if (_settings.remove_speed_orient) {
        speed_orient = speed_orient - step;
    }

    yaw = std::clamp<double>(yaw, -30.0, 30.0); ;
    pitch = std::clamp<double>(pitch, 5.0, 55.0);
    speed = std::clamp<double>(speed, 8.0, 22.0);
    speed_orient = std::clamp<double>(speed_orient, 20.0, 100.0);


    previousDir = shotSets.direction;

    CalculDir();

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

cyclone::Vector3 Launcher::CalculDir()
{
    cyclone::Vector3 dir = { 1, 0, 0 };
    float rotaPitch = (float)pitch * DEG2RAD; // en radian
    float rotaYaw = (float)yaw * DEG2RAD;

    Vector4 base = { 0 };
    base.x = dir.x;
    base.y = dir.y;
    base.z = dir.z;
    base.w = 0;
    
    base = base*MatrixRotateZ(rotaPitch);
    base = base*MatrixRotateY(rotaYaw);
    
    shotSets.direction = { base.x, base.y, base.z };
    
    //shotSets.direction.x = cosf(rotaYaw) * cosf(rotaPitch);
    //shotSets.direction.y = sinf(rotaPitch);
    //shotSets.direction.z = sinf(rotaYaw) * cosf(rotaPitch);

    return shotSets.direction;
}


void Launcher::draw(InputSnapshot _snapshot, float _dt)
{
    //TODO draw launcher
    Vector3 startPoint = { -5.0f, 0.75f, 0.0f };
    aim(_snapshot, _dt);
    cyclone::Vector3 launcherDir = shotSettings().direction;
    double lengthLine = 10;
    Vector3 movePoint =
        Vector3(
            startPoint.x + launcherDir.x * lengthLine,
            startPoint.y + launcherDir.y * lengthLine,
            startPoint.z + launcherDir.z * lengthLine
        );

    DrawLine3D(startPoint, movePoint, RED);
    DrawCube(startPoint, 0.5f, 1.5f, 0.5f, BLUE);
}



ShotSettings& Launcher::shotSettings()
{
    
    return shotSets;
}
