// Gil Miranda
#pragma once
#include <allegro5/allegro.h>

class Enemy
{
public:

    float x;
    float y;

    float width;
    float height;

    float leftBound;
    float rightBound;

    float speed;

    ALLEGRO_BITMAP* sprite;

    int currentFrame;
    int frameTimer;

    // Constructor that sets the enemy position and patrol boundaries.
    Enemy(
        float startX,
        float startY,
        float left,
        float right);

    // Updates enemy movement and animation.
    void update();

    // Draws the enemy on the screen.
    void draw(float cameraX);
};