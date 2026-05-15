#include <raylib.h>
#include "consts.h"
#include "rigidbody.h"

RigidBody CreateRigidBody(Vector3 position, float mass, bool isStatic, Mesh shape, Color color) {
    RigidBody body = (RigidBody){
        .position = position,
        .velocity = (Vector3){0.0f, 0.0f, 0.0f},
        .acceleration = (Vector3){0.0f, 0.0f, 0.0f},
        .mass = mass,
        .isStatic = isStatic,
        .shape = LoadModelFromMesh(shape),
        .color = color
    };
    return body;
}

void UpdateRigidBody(RigidBody * self) {
    float dt = GetFrameTime();
    if (!self->isStatic) {
        // Apply gravity
        self->acceleration = GRAVITY;

        // Update velocity
        self->velocity.x += (self->mass * self->acceleration.x) * dt;
        self->velocity.y += (self->mass * self->acceleration.y) * dt;
        self->velocity.z += (self->mass * self->acceleration.z) * dt;

        // Update position
        self->position.x += self->velocity.x * dt;
        self->position.y += self->velocity.y * dt;
        self->position.z += self->velocity.z * dt;
    }
}

void DrawRigidBody(RigidBody self) {
    DrawModel(self.shape, self.position, 1.0f, self.color);
}