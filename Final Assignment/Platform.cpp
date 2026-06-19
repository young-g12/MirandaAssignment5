#include "Platform.h"

#include <allegro5/allegro_primitives.h>

// Constructor that initializes the platform's position and size.
Platform::Platform(
    float px,
    float py,
    float w,
    float h)
{
    x = px;
    y = py;

    width = w;
    height = h;
}

// Draws the platform on the screen.
void Platform::draw(float cameraX)
{
    al_draw_filled_rectangle(
        x - cameraX,
        y,
        x + width - cameraX,
        y + height,
        al_map_rgb(120, 120, 120));
}