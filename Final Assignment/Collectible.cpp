// Gil Miranda
#include "Collectible.h"
#include <allegro5/allegro_image.h>
#include <cstdio>

#include <allegro5/allegro_primitives.h>

// Constructor that initializes a collectible object.
Collectible::Collectible(
    float px,
    float py)
{
    x = px;
    y = py;

    size = 20;

    collected = false;

    rotation = 0;

    // Load the collectible sprite image.
    sprite =
        al_load_bitmap(
            "C:/Users/gmira/source/repos/Final Assignment/x64/Debug/Rock1.png");

    if (!sprite)
    {
        printf("FAILED TO LOAD COLLECTIBLE\n");
    }

    angle = 0;
}

// Updates the collectible each frame.
void Collectible::update()
{
    rotation += 0.05f;
}

// Draws the collectible on the screen.
void Collectible::draw(float cameraX)
{
    if (!collected)
    {
        al_draw_scaled_rotated_bitmap(
            sprite,

            al_get_bitmap_width(sprite) / 2,
            al_get_bitmap_height(sprite) / 2,

            x - cameraX,
            y,

            2.5,
            2.5,

            rotation,

            0);
    }
}