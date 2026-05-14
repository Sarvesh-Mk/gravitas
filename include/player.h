#include "../raylib/raylib.h"

typedef struct Player {
    Vector3 position;
    Vector3 velocity;
    Camera3D camera;
} Player;

Player CreatePlayer(float x, float y, float z);

void UpdatePlayer(Player * self);