// Gil Miranda
#pragma once

class Platform
{
public:

    float x;
    float y;

    float width;
    float height;

    // Constructor that sets the platform position and size.
    Platform(
        float px,
        float py,
        float w,
        float h);

    void draw(float cameraX);
};