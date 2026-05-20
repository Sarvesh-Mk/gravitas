#include <raylib.h>
#include <raymath.h>
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
        .hitbox = GetModelBoundingBox(LoadModelFromMesh(shape)),
        .color = color
    };
    body.hitbox.min = Vector3Add(body.position, body.hitbox.min);
    body.hitbox.max = Vector3Add(body.position, body.hitbox.max);
    return body;
}

/*
For collisions I want it to be done in 2 stages like its done in many games

Stage 1: Broad Phase - This is a quick check to see if the bounding boxes of the two rigid bodies overlap. If they don't, we can skip the more detailed collision check.
- going to use Raylibs implementation of bounding boxes for this, which is the GetModelBoundingBox function, 
    - returns a BoundingBox struct with min and max Vector3 values. We can then check if the bounding boxes of the two rigid bodies overlap by comparing their min and max values.

Stage 2: Narrow Phase - If the bounding boxes do overlap, we can then perform a more detailed collision check. 
- This could involve checking the actual vertices of the models against each other, or using a more complex collision detection algorithm like SAT (Separating Axis Theorem) 

NOTE: Also need a way to check recursivly check collision for all bodies
*/

// TBD 
int CheckAllCollisions(RigidBody body1, RigidBody *bodies) {
    for(int i = 0; i < sizeof(bodies)/sizeof(RigidBody); i++) {
        if (BroadCollisionCheck(bodies[i], body1)) {
            // Perform narrow phase collision check here
            return 0;
        } 
    }
    UpdateRigidBody(&body1);
}

bool BroadCollisionCheck(RigidBody body1, RigidBody body2) {
    return CheckCollisionBoxes(body1.hitbox, body2.hitbox);
}


void UpdateRigidBody(RigidBody *self) {
    float dt = GetFrameTime();
    
    // Apply gravity (if not static)
    if (!self->isStatic) {        
        // Apply gravity
        self->acceleration = GRAVITY;

        // Update velocity
        self->velocity = Vector3Add(self->velocity, Vector3Scale(self->acceleration, dt));

        // Update position
        self->position = Vector3Add(self->position, Vector3Scale(self->velocity, dt));
    
        BoundingBox base = GetModelBoundingBox(self->shape);
        self->hitbox.min = Vector3Add(self->position, base.min);
        self->hitbox.max = Vector3Add(self->position, base.max);
    }
}

void DrawRigidBody(RigidBody self) {
    DrawModel(self.shape, self.position, 1.0f, self.color);
    DrawBoundingBox(self.hitbox, GREEN);
}