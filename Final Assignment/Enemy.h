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

    Enemy(
        float startX,
        float startY,
        float left,
        float right);

    void update();

    void draw(float cameraX);
};