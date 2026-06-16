#include "Collectible.h"

#include <allegro5/allegro_primitives.h>

Collectible::Collectible(
    float px,
    float py)
{
    x = px;
    y = py;

    size = 20;

    collected = false;

    angle = 0;
}

void Collectible::update()
{
    angle += 0.05f;
}

void Collectible::draw(float cameraX)
{
    if (collected)
        return;

    al_draw_filled_circle(
        x - cameraX,
        y,
        size,
        al_map_rgb(255, 215, 0)
    );
}