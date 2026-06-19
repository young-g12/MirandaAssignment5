// Gil Miranda
#pragma once

#include <allegro5/allegro.h>

class Player
{
public:

    float x;
    float y;

    float width;
    float height;

    float velX;
    float velY;

    // Tracks whether the player is standing on a platform.
    bool onGround;

    int score;
    int health;

    // Frames of temporary invincibility after taking damage.
    int invincibilityFrames;

    int currentFrame;
    int frameTimer;

    // Sprite used to draw the player.
    ALLEGRO_BITMAP* idleSprite;

    Player();

    // Updates player movement, physics, and game logic.
    void update();

    void draw(float cameraX);
};