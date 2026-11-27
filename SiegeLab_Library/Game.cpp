#include "Game.h"

#include <cyclone/collide_fine.h>
#include <cyclone/contacts.h>
#include <cyclone/core.h>

#include "raylib.h"

#include "HeavyProjectile.h"
#include "InputController.h"
#include "Launcher.h"
#include "OrbitCamera.h"
#include "StandardProjectile.h"

namespace
{

    constexpr float kFixedDt = 1.0f / 60.0f;
    constexpr int kMaxContacts = 16;

    void StepProjectileFixed(Projectile& _proj, cyclone::ContactResolver& _resolver)
    {
        cyclone::RigidBody& body = _proj.   Body();
        body.integrate(kFixedDt);
        cyclone::CollisionSphere& sphere = _proj.MutableSphere();
        sphere.calculateInternals();

        cyclone::CollisionPlane ground;
        ground.direction = cyclone::Vector3(0.0, 1.0, 0.0);
        ground.offset = 0.0;

        cyclone::Contact contacts[kMaxContacts];
        cyclone::CollisionData data;
        data.contactArray = contacts;
        data.reset(kMaxContacts);
        data.friction = 0.5;
        data.restitution = 0.0;
        data.tolerance = 0.01;

        cyclone::CollisionDetector::sphereAndHalfSpace(sphere, ground, &data);
        if (data.contactCount > 0)
        {
            _resolver.resolveContacts(data.contactArray, data.contactCount, kFixedDt);
            body.calculateDerivedData();
            sphere.calculateInternals();
        }
    }

}  // namespace

void Game::Run()
{
    InitWindow(1280, 720, "Siege Lab");
    SetTargetFPS(60);

    InputController input;
    OrbitCamera camera;
    Launcher launcher;
    cyclone::ContactResolver resolver(32);
    StandardProjectile std_proj;
    HeavyProjectile heavy_proj;
    Projectile* active_proj = nullptr;
    float accumulator = 0.0f;

    while (!WindowShouldClose())
    {
        const float frame_dt = GetFrameTime();
        const InputSnapshot snap = input.Capture();
        camera.update(snap, frame_dt);
        launcher.Aim(snap, frame_dt);

        if (snap.fire_pressed_space)
        {
            ShotSettings settings = launcher.GetShotSettings();
            settings.origin = cyclone::Vector3(-8.0, 1.0, 0.0);
            active_proj = (settings.projectile_kind == ProjectileKind::kHeavy)
                ? static_cast<Projectile*>(&heavy_proj)
                : static_cast<Projectile*>(&std_proj);
            active_proj->Fire(settings);
        }

        accumulator += frame_dt;
        while (accumulator >= kFixedDt)
        {
            if (active_proj != nullptr)
            {
                StepProjectileFixed(*active_proj, resolver);
            }
            accumulator -= kFixedDt;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera.getCamera());
        if (active_proj != nullptr)
        {
            active_proj->Draw();
        }
        DrawGrid(10, 1.0f);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}