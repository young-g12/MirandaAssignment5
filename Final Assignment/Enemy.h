#pragma once

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

    Enemy(
        float startX,
        float startY,
        float left,
        float right);

    void update();

    void draw(float cameraX);
};