// Gil Miranda
#include "Player.h"


#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <cstdio>

Player::Player()
{
    x = 100;
    y = 300;

    width = 96;
    height = 96;

    velX = 0;
    velY = 0;

    onGround = false;

    score = 0;
    health = 100;

    invincibilityFrames = 0;

    currentFrame = 0;
    frameTimer = 0;

    // Load the player's sprite sheet.
    idleSprite =
        al_load_bitmap(
            "C:/Users/gmira/source/repos/Final Assignment/x64/Debug/Dude_Monster_Idle_4.png");

    if (!idleSprite)
    {
        printf("FAILED TO LOAD PLAYER SPRITE\n");
    }
    else
    {
        printf("PLAYER SPRITE LOADED\n");
    }
        

}

void Player::update()
{
    velY += 0.4f;

    x += velX;
    y += velY;

    if (invincibilityFrames > 0)
    {
        invincibilityFrames--;
    }

    frameTimer++;

    if (frameTimer >= 10)
    {
        frameTimer = 0;

        currentFrame++;

        if (currentFrame >= 4)
        {
            currentFrame = 0;
        }
    }
}

// Draws the player sprite on the screen.
void Player::draw(float cameraX)
{
    if (idleSprite)
    {
        al_draw_scaled_bitmap(
            idleSprite,

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
        // Draw a green rectangle if the sprite fails to load.
        al_draw_filled_rectangle(
            x - cameraX,
            y,
            x + width - cameraX,
            y + height,
            al_map_rgb(0, 255, 0));

    }
}