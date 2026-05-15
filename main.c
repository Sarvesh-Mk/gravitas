#include <raylib.h>
#include "player.h"
#include "consts.h"
#include "rigidbody.h"

int main(void){
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Gravitas - A physics engine"); 
    DisableCursor();
    SetTargetFPS(60);

    Player player = CreatePlayer(-10.0f, 10.0f, 0.0f);
    RigidBody cube = CreateRigidBody((Vector3){0.0f, 10.0f, 0.0f}, 1.0f, false, GenMeshCube(2.0f, 2.0f, 2.0f), RED);
    RigidBody floor = CreateRigidBody((Vector3){0.0f, -1.0f, 0.0f}, 1.0f, true, GenMeshCube(20.0f, 2.0f, 20.0f), LIGHTGRAY);

    while (!WindowShouldClose()){
        
        UpdatePlayer(&player);
        UpdateRigidBody(&cube);
        UpdateRigidBody(&floor);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(player.camera);

                DrawRigidBody(cube);
                DrawRigidBody(floor);

            EndMode3D();
            
            DrawText("A physics engine I'm making :)", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}