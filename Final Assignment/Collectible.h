//Gil Miranda
#pragma once
#include <allegro5/allegro.h>

class Collectible
{
public:

    float x;
    float y;

    float size;

    // Tracks whether the collectible has been collected.
    bool collected;

    float angle;

    ALLEGRO_BITMAP* sprite;

    float rotation;

    // Constructor that sets the starting position.
    Collectible(
        float px,
        float py);

    void update();

    void draw(float cameraX);
};