#include "Collectible.h"
#include <allegro5/allegro_image.h>
#include <cstdio>

#include <allegro5/allegro_primitives.h>

Collectible::Collectible(
    float px,
    float py)
{
    x = px;
    y = py;

    size = 20;

    collected = false;

    sprite =
        al_load_bitmap(
            "C:/Users/gmira/source/repos/Final Assignment/x64/Debug/Rock1.png");

    if (!sprite)
    {
        printf("FAILED TO LOAD COLLECTIBLE\n");
    }

    angle = 0;
}

void Collectible::update()
{
    angle += 0.05f;
}

void Collectible::draw(float cameraX)
{
    if (collected)
    {
        return;
    }

    if (sprite)
    {
        al_draw_scaled_bitmap(
            sprite,

            0,
            0,

            al_get_bitmap_width(sprite),
            al_get_bitmap_height(sprite),

            x - cameraX - 20,
            y - 20,

            40,
            40,

            0);
    }
}