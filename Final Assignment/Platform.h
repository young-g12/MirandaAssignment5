#pragma once

class Platform
{
public:

    float x;
    float y;

    float width;
    float height;

    Platform(
        float px,
        float py,
        float w,
        float h);

    void draw(float cameraX);
};