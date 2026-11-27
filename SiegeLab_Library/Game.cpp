#include "pch.h"
#include "framework.h"

#include "Game.h"
#include "InputController.h"
#include "OrbitCamera.h"
#include "Launcher.h"

#include "raylib.h"
#include "cyclone/core.h"

void Game::Run()
{
    InitWindow(1280, 720, "Test Camera");
    SetTargetFPS(60);

    InputController input;
    OrbitCamera camera;
    Launcher launcher;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        InputSnapshot snapshot = input.capture();
        camera.update(snapshot, dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera.getCamera());
        DrawCube({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires({ 0.0f, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, MAROON);

        launcher.draw(snapshot, dt);

        DrawGrid(10, 1.0f);
        EndMode3D();
        DrawText("Press R to reset camera position", 20, 20, 30, BLACK);
        EndDrawing();
    }

    CloseWindow();
}
