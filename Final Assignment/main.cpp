#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Player.h"
#include "Platform.h"

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

int main()
{
    al_init();

    al_install_keyboard();

    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display =
        al_create_display(
            SCREEN_W,
            SCREEN_H);

    ALLEGRO_EVENT_QUEUE* queue =
        al_create_event_queue();

    ALLEGRO_TIMER* timer =
        al_create_timer(1.0 / 60.0);

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

    vector<Platform> platforms;

    platforms.push_back(
        Platform(
            0,
            650,
            3000,
            70));

    platforms.push_back(
        Platform(
            300,
            550,
            200,
            20));

    platforms.push_back(
        Platform(
            700,
            450,
            200,
            20));

    platforms.push_back(
        Platform(
            1200,
            350,
            200,
            20));

    float cameraX = 0;

    al_start_timer(timer);

    while (running)
    {
        ALLEGRO_EVENT event;

        al_wait_for_event(
            queue,
            &event);

        if (event.type ==
            ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            running = false;
        }

        else if (
            event.type ==
            ALLEGRO_EVENT_KEY_DOWN)
        {
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
        }

        else if (
            event.type ==
            ALLEGRO_EVENT_KEY_UP)
        {
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
        }

        else if (
            event.type ==
            ALLEGRO_EVENT_TIMER)
        {
            if (keys[LEFT])
            {
                player.velX = -5;
            }
            else if (keys[RIGHT])
            {
                player.velX = 5;
            }
            else
            {
                player.velX = 0;
            }

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
                    player.x + player.width >
                    platform.x &&

                    player.x <
                    platform.x + platform.width &&

                    player.y + player.height >=
                    platform.y &&

                    player.y + player.height <=
                    platform.y + 20 &&

                    player.velY >= 0)
                {
                    player.y =
                        platform.y -
                        player.height;

                    player.velY = 0;

                    player.onGround = true;
                }
            }

            cameraX =
                player.x -
                SCREEN_W / 2;

            if (cameraX < 0)
            {
                cameraX = 0;
            }

            redraw = true;
        }

        if (redraw &&
            al_is_event_queue_empty(queue))
        {
            redraw = false;

            al_clear_to_color(
                al_map_rgb(
                    50,
                    50,
                    80));

            for (auto& platform : platforms)
            {
                platform.draw(
                    cameraX);
            }

            player.draw(
                cameraX);

            al_flip_display();
        }
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}