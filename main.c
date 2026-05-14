#include "raylib/raylib.h"
#include "include/player.h"
#include "include/consts.h"

int main(void){
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Player player = CreatePlayer(-10.0f, 10.0f, 0.0f);

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        
        UpdatePlayer(&player);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(player.camera);

                DrawGrid(10, 1.0f);

            EndMode3D();
            
            DrawText("A physics engine I'm making :)", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}