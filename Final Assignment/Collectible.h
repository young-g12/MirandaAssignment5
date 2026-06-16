#pragma once

class Collectible
{
public:

    float x;
    float y;

    float size;

    bool collected;

    float angle;

    Collectible(
        float px,
        float py);

    void update();

    void draw(float cameraX);
};