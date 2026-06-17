#include "Player.h"

#include <allegro5/allegro_primitives.h>

Player::Player()
{
    x = 100;
    y = 300;

    width = 50;
    height = 50;

    velX = 0;
    velY = 0;

    onGround = false;

    score = 0;
    health = 100;

    invincibilityFrames = 0;
}

void Player::update()
{
    velY += 0.5f;

    x += velX;
    y += velY;

    if (invincibilityFrames > 0)
    {
        invincibilityFrames--;
    }
}

void Player::draw(float cameraX)
{
    if (invincibilityFrames > 0)
    {
        al_draw_filled_rectangle(
            x - cameraX,
            y,
            x + width - cameraX,
            y + height,
            al_map_rgb(255, 255, 0));
    }
    else
    {
        al_draw_filled_rectangle(
            x - cameraX,
            y,
            x + width - cameraX,
            y + height,
            al_map_rgb(0, 255, 0));
    }
}