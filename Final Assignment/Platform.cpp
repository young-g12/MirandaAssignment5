#include "Platform.h"

#include <allegro5/allegro_primitives.h>

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

void Platform::draw(float cameraX)
{
    al_draw_filled_rectangle(
        x - cameraX,
        y,
        x + width - cameraX,
        y + height,
        al_map_rgb(120, 120, 120)
    );
}