#pragma once

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

    Player();

    void update();

    void draw(float cameraX);
};