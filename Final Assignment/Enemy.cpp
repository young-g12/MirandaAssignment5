#include "Enemy.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <cstdio>

Enemy::Enemy(
    float startX,
    float startY,
    float left,
    float right)
{
    x = startX;
    y = startY;

    width = 96;
    height = 96;

    leftBound = left;
    rightBound = right;

    speed = 2;

    sprite =
        al_load_bitmap(
            "C:/Users/gmira/source/repos/Final Assignment/x64/Debug/Pink_Monster_Walk_6.png");

    currentFrame = 0;
    frameTimer = 0;
}

void Enemy::update()
{
    x += speed;

    if (x <= leftBound ||
        x + width >= rightBound)
    {
        speed *= -1;
    }

    frameTimer++;

    if (frameTimer >= 8)
    {
        frameTimer = 0;

        currentFrame++;

        if (currentFrame >= 6)
        {
            currentFrame = 0;
        }
    }
}

void Enemy::draw(float cameraX)
{
    if (sprite)
    {
        al_draw_scaled_bitmap(
            sprite,

            currentFrame * 32,
            0,

            32,
            32,

            x - cameraX,
            y,

            width,
            height,

            0);
    }
    else
    {
        al_draw_filled_rectangle(
            x - cameraX,
            y,
            x + width - cameraX,
            y + height,
            al_map_rgb(255, 0, 0));
    }
}