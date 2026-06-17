#include <vector>
#include <cmath>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "Player.h"
#include "Platform.h"
#include "Collectible.h"
#include "Enemy.h"

using namespace std;

const int SCREEN_W = 1280;
const int SCREEN_H = 720;

enum Keys
{
    LEFT,
    RIGHT,
    UP,
    ESC
};

void loadLevel(
    int level,
    vector<Platform>& platforms,
    vector<Collectible>& collectibles,
    vector<Enemy>& enemies)
{
    platforms.clear();
    collectibles.clear();
    enemies.clear();

    if (level == 1)
    {
        platforms.push_back(
            Platform(0, 650, 3000, 70));

        platforms.push_back(
            Platform(300, 550, 200, 20));

        platforms.push_back(
            Platform(700, 450, 200, 20));

        platforms.push_back(
            Platform(1200, 350, 200, 20));

        collectibles.push_back(
            Collectible(350, 500));

        collectibles.push_back(
            Collectible(750, 400));

        collectibles.push_back(
            Collectible(1250, 300));

        enemies.push_back(
            Enemy(600, 600, 500, 900));

        enemies.push_back(
            Enemy(1500, 600, 1400, 1800));
    }
    else if (level == 2)
    {
        platforms.push_back(
            Platform(0, 650, 3500, 70));

        platforms.push_back(
            Platform(400, 550, 200, 20));

        platforms.push_back(
            Platform(900, 450, 200, 20));

        platforms.push_back(
            Platform(1500, 350, 200, 20));

        platforms.push_back(
            Platform(2200, 450, 200, 20));

        collectibles.push_back(
            Collectible(450, 500));

        collectibles.push_back(
            Collectible(950, 400));

        collectibles.push_back(
            Collectible(1550, 300));

        collectibles.push_back(
            Collectible(2250, 400));

        enemies.push_back(
            Enemy(700, 600, 600, 1100));

        enemies.push_back(
            Enemy(1800, 600, 1700, 2200));

        enemies.push_back(
            Enemy(2600, 600, 2500, 3200));
    }
    else if (level == 3)
    {
        platforms.push_back(
            Platform(0, 650, 4000, 70));

        platforms.push_back(
            Platform(500, 550, 200, 20));

        platforms.push_back(
            Platform(1200, 450, 200, 20));

        platforms.push_back(
            Platform(1900, 350, 200, 20));

        platforms.push_back(
            Platform(2700, 450, 200, 20));

        collectibles.push_back(
            Collectible(550, 500));

        collectibles.push_back(
            Collectible(1250, 400));

        collectibles.push_back(
            Collectible(1950, 300));

        collectibles.push_back(
            Collectible(2750, 400));

        collectibles.push_back(
            Collectible(3400, 500));

        enemies.push_back(
            Enemy(700, 600, 600, 1100));

        enemies.push_back(
            Enemy(1600, 600, 1500, 2100));

        enemies.push_back(
            Enemy(2500, 600, 2400, 3000));

        enemies.push_back(
            Enemy(3300, 600, 3200, 3800));
    }
}

int main()
{
    al_init();
    al_install_keyboard();

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY* display =
        al_create_display(
            SCREEN_W,
            SCREEN_H);

    if (!display)
        return -1;

    ALLEGRO_EVENT_QUEUE* queue =
        al_create_event_queue();

    ALLEGRO_TIMER* timer =
        al_create_timer(
            1.0 / 60.0);

    ALLEGRO_FONT* font =
        al_create_builtin_font();

    al_register_event_source(
        queue,
        al_get_keyboard_event_source());

    al_register_event_source(
        queue,
        al_get_display_event_source(display));

    al_register_event_source(
        queue,
        al_get_timer_event_source(timer));

    bool running = true;
    bool redraw = true;

    bool keys[4] = { false };

    Player player;

    int currentLevel = 1;

    vector<Platform> platforms;
    vector<Collectible> collectibles;
    vector<Enemy> enemies;

    loadLevel(
        currentLevel,
        platforms,
        collectibles,
        enemies);

    float cameraX = 0;

    al_start_timer(timer);

    while (running)
    {
        ALLEGRO_EVENT event;

        al_wait_for_event(
            queue,
            &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            running = false;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:

            switch (event.keyboard.keycode)
            {
            case ALLEGRO_KEY_A:
                keys[LEFT] = true;
                break;

            case ALLEGRO_KEY_D:
                keys[RIGHT] = true;
                break;

            case ALLEGRO_KEY_SPACE:
                keys[UP] = true;
                break;

            case ALLEGRO_KEY_ESCAPE:
                keys[ESC] = true;
                break;
            }
            break;

        case ALLEGRO_EVENT_KEY_UP:

            switch (event.keyboard.keycode)
            {
            case ALLEGRO_KEY_A:
                keys[LEFT] = false;
                break;

            case ALLEGRO_KEY_D:
                keys[RIGHT] = false;
                break;

            case ALLEGRO_KEY_SPACE:
                keys[UP] = false;
                break;

            case ALLEGRO_KEY_ESCAPE:
                keys[ESC] = false;
                break;
            }
            break;

        case ALLEGRO_EVENT_TIMER:

            if (keys[LEFT])
                player.velX = -5;
            else if (keys[RIGHT])
                player.velX = 5;
            else
                player.velX = 0;

            if (keys[UP] &&
                player.onGround)
            {
                player.velY = -12;
                player.onGround = false;
            }

            player.update();

            player.onGround = false;

            for (auto& platform : platforms)
            {
                if (
                    player.x + player.width > platform.x &&
                    player.x < platform.x + platform.width &&
                    player.y + player.height >= platform.y &&
                    player.y + player.height <= platform.y + 20 &&
                    player.velY >= 0)
                {
                    player.y =
                        platform.y -
                        player.height;

                    player.velY = 0;
                    player.onGround = true;
                }
            }

            for (auto& c : collectibles)
            {
                c.update();

                if (c.collected)
                    continue;

                float dx =
                    (player.x + player.width / 2) - c.x;

                float dy =
                    (player.y + player.height / 2) - c.y;

                float distance =
                    sqrt(dx * dx + dy * dy);

                if (distance < 40)
                {
                    c.collected = true;
                    player.score += 100;
                }
            }

            bool allCollected = true;

            for (auto& c : collectibles)
            {
                if (!c.collected)
                {
                    allCollected = false;
                    break;
                }
            }

            if (allCollected)
            {
                currentLevel++;

                player.x = 100;
                player.y = 300;

                if (currentLevel <= 3)
                {
                    loadLevel(
                        currentLevel,
                        platforms,
                        collectibles,
                        enemies);
                }
                else
                {
                    running = false;
                }
            }

            for (auto& enemy : enemies)
            {
                enemy.update();
            }

            for (auto& enemy : enemies)
            {
                bool collision =
                    player.x < enemy.x + enemy.width &&
                    player.x + player.width > enemy.x &&
                    player.y < enemy.y + enemy.height &&
                    player.y + player.height > enemy.y;

                if (collision &&
                    player.invincibilityFrames == 0)
                {
                    player.health -= 10;

                    player.invincibilityFrames = 60;

                    if (player.health < 0)
                    {
                        player.health = 0;
                    }
                }
            }

            if (player.health <= 0)
            {
                running = false;
            }

            cameraX =
                player.x -
                SCREEN_W / 2;

            if (cameraX < 0)
            {
                cameraX = 0;
            }

            redraw = true;
            break;
        }

        if (redraw &&
            al_is_event_queue_empty(queue))
        {
            redraw = false;

            al_clear_to_color(
                al_map_rgb(40, 40, 70));

            for (auto& platform : platforms)
            {
                platform.draw(cameraX);
            }

            for (auto& c : collectibles)
            {
                c.draw(cameraX);
            }

            for (auto& enemy : enemies)
            {
                enemy.draw(cameraX);
            }

            player.draw(cameraX);

            al_draw_filled_rectangle(
                0,
                0,
                SCREEN_W,
                40,
                al_map_rgb(0, 0, 0));

            al_draw_textf(
                font,
                al_map_rgb(255, 255, 255),
                20,
                10,
                0,
                "Score: %d",
                player.score);

            al_draw_textf(
                font,
                al_map_rgb(255, 255, 255),
                220,
                10,
                0,
                "Health: %d",
                player.health);

            al_draw_textf(
                font,
                al_map_rgb(255, 255, 255),
                450,
                10,
                0,
                "Level: %d",
                currentLevel);

            al_flip_display();
        }

        if (keys[ESC])
        {
            running = false;
        }
    }

    al_destroy_font(font);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}