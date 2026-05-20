#include <raylib.h>

typedef struct RigidBody{
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float mass;
    bool isStatic;

    Model shape; // Pointer to the shape of the rigidbody, can be a cube, sphere, etc.
    BoundingBox hitbox;
    Color color;
} RigidBody;

RigidBody CreateRigidBody(Vector3 position, float mass, bool isStatic, Mesh shape, Color color);
void UpdateRigidBody(RigidBody * self);
void DrawRigidBody(RigidBody self);
bool BroadCollisionCheck(RigidBody body1, RigidBody body2);