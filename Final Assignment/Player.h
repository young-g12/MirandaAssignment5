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

    bool onGround;

    int score;
    int health;

    int invincibilityFrames;

    int currentFrame;
    int frameTimer;

    ALLEGRO_BITMAP* idleSprite;

    Player();

    void update();

    void draw(float cameraX);
};