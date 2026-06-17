#include "Enemy.h"

#include <allegro5/allegro_primitives.h>

Enemy::Enemy(
    float startX,
    float startY,
    float left,
    float right)
{
    x = startX;
    y = startY;

    width = 50;
    height = 50;

    leftBound = left;
    rightBound = right;

    speed = 2;
}

void Enemy::update()
{
    x += speed;

    if (x <= leftBound ||
        x + width >= rightBound)
    {
        speed *= -1;
    }
}

void Enemy::draw(float cameraX)
{
    al_draw_filled_rectangle(
        x - cameraX,
        y,
        x + width - cameraX,
        y + height,
        al_map_rgb(255, 0, 0));
}