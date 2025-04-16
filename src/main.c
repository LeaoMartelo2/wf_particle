#include "../raylib/raylib.h"
#include "../raylib/raymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICLES 500

#define PARTICLE_ACCELERATION_X 0.0f
#define PARTICLE_ACCELERATION_Y 0.05f

#define PARTICLE_VEL_RANGE_X -5, 5
#define PARTICLE_VEL_RANGE_Y -50, -20

#define PARTICLE_SPAWN_DEVIATION 20

#define PARTICLE_INITIAL_SIZE 5.0f

#define PARTICLE_MAIN_COLOR ORANGE
#define PARTICLE_ALT_COLOR RED

#define PARTICLE_DECAY_RATE -0.05f

typedef struct Particle {

    Vector2 pos;
    Vector2 velocity;
    float size;
    Color color;

} Particle;

void particle_draw(Particle *particle) {

    if (particle->size < 0.1f) {
        return;
    }

    DrawCircle(particle->pos.x, particle->pos.y, particle->size, particle->color);
}

void particle_update(Particle *particle) {

    if (particle->size < 0.0f) {
        return;
    }

    Vector2 acceleration = {PARTICLE_ACCELERATION_X, PARTICLE_ACCELERATION_Y};

    Vector2 velocity = {
        (float)GetRandomValue(PARTICLE_VEL_RANGE_X) * 0.1f,
        (float)GetRandomValue(PARTICLE_VEL_RANGE_Y) * 0.1f,
    };

    particle->velocity = Vector2Add(velocity, acceleration);
    particle->pos = Vector2Add(particle->pos, particle->velocity);

    particle->size += PARTICLE_DECAY_RATE;
}

void particle_populate(Particle *particle, Vector2 mouse_pos) {

    Vector2 range_pos = {0};

    range_pos.x = (float)GetRandomValue((mouse_pos.x - PARTICLE_SPAWN_DEVIATION),
                                        mouse_pos.x + PARTICLE_SPAWN_DEVIATION);

    range_pos.y = (float)GetRandomValue((mouse_pos.y - PARTICLE_SPAWN_DEVIATION),
                                        mouse_pos.y + PARTICLE_SPAWN_DEVIATION);

    particle->size = PARTICLE_INITIAL_SIZE;

    particle->pos = range_pos;

    int rand_color = GetRandomValue(1, 10);

    if (rand_color > 7) {
        particle->color = PARTICLE_ALT_COLOR;
    } else {
        particle->color = PARTICLE_MAIN_COLOR;
    }
}

typedef struct Particle_arr {
    Particle items[MAX_PARTICLES];
    size_t count;
} Particle_arr;

void particles_arr_draw(Particle_arr *particles) {

    for (size_t i = 0; i < MAX_PARTICLES; ++i) {

        particle_draw(&particles->items[i]);
    }
}

void particles_arr_update(Particle_arr *particles) {

    for (size_t i = 0; i < MAX_PARTICLES; ++i) {

        particle_update(&particles->items[i]);
    }
}

int main(void) {

    SetRandomSeed(185);

    InitWindow(800, 600, "wf_particle");

    SetTargetFPS(60);

    Vector2 mouse_pos = {0};

    Particle_arr particles = {0};

    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            mouse_pos = GetMousePosition();

            Particle tmp_part = {0};
            particle_populate(&tmp_part, mouse_pos);

            if (particles.count < MAX_PARTICLES) {
                particles.items[particles.count++] = tmp_part;

            } else {
                particles.count = 0;
            }
        }

        particles_arr_update(&particles);

        BeginDrawing();

        ClearBackground(BLACK);

        particles_arr_draw(&particles);

        EndDrawing();
    }

    return 0;
}
