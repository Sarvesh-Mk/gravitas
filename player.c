#include <raylib.h>
#include "player.h"

void UpdatePlayer(Player * self) {
  // Implementation for updating player state
  UpdateCameraPro(&self->camera,
    (Vector3){
        (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.1f -      // Move forward-backward
        (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.1f,
        (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.1f -   // Move right-left
        (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.1f,
        IsKeyDown(KEY_SPACE)*0.1f -
        IsKeyDown(KEY_LEFT_SHIFT)*0.1f      // Move up-down
    },
    (Vector3){
        GetMouseDelta().x*0.05f,                            // Rotation: yaw
        GetMouseDelta().y*0.05f,                            // Rotation: pitch
        0.0f                                                // Rotation: roll
    },
    //GetMouseWheelMove()*2.0f                                // Move to target (zoom)
    0.0f
  );                              
}

Player CreatePlayer(float x, float y, float z) {
    Player player;
    player.position = (Vector3){x, y, z};
    player.velocity = (Vector3){0, 0, 0};
    player.camera = (Camera3D){
        .position = (Vector3){0, 10.0f, 10.0f},
        .target = (Vector3){0, 0, 0},
        .up = (Vector3){0, 1, 0},
        .fovy = 45.0f,
        .projection = CAMERA_PERSPECTIVE
    };
    return player;
}

