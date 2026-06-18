#pragma once
#include <allegro5/allegro.h>

class Collectible
{
public:

    float x;
    float y;

    float size;

    bool collected;

    float angle;

    ALLEGRO_BITMAP* sprite;

    float rotation;

    Collectible(
        float px,
        float py);

    void update();

    void draw(float cameraX);
};