/*
** EPITECH PROJECT, 2022
** project_myhunter
** File description:
** my_hunter
*/

#include "my.h"

static sfRenderWindow * create_renderwindow
(unsigned int x, unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

int end_function(sfRenderWindow *window)
{
    sfEvent menu;
    sfTexture *gameover_texture =
    sfTexture_createFromFile("ressources/gameover.png", NULL);
    sfSprite *gameover_sprite = sfSprite_create();
    sfTexture *end_texture =
    sfTexture_createFromFile("ressources/end.png", NULL);
    sfSprite *end_sprite = sfSprite_create();
    sfVector2f pos_gameover = {750, 200};
    sfVector2f scale_gameover = {2, 2};
    sfSprite_setTexture(gameover_sprite, gameover_texture, sfTrue);
    sfSprite_setTexture(end_sprite, end_texture, sfTrue);
    sfSprite_setPosition(gameover_sprite, pos_gameover);
    sfSprite_setScale(gameover_sprite, scale_gameover);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &menu)) {
            event2(window, menu);
        }
        end_reinitialisation(window, end_sprite, gameover_sprite);
    }
    return 0;
}

int initialisation_all(gamecore_t *gamecore,
sprite_t *sprite, duration_t *duration, image_t *image)
{
    initialisation_sprite(sprite, image);
    initialisation_sprite1(sprite, image);
    initialisation_sprite2(sprite, image);
    initialisation_sprite3(sprite, image);
    initialisation_sprite4(sprite, image);
    initialisation_sprite5(sprite, image);
    initialisation_music(gamecore);
    initialisation_clock(duration);
}

int game_function(sfRenderWindow *window)
{
    gamecore_t gamecore;
    sprite_t sprite;
    image_t image;
    duration_t duration;
    int check;
    gamecore.window = window;
    initialisation_all(&gamecore, &sprite, &duration, &image);
    while (sfRenderWindow_isOpen(gamecore.window)) {
        sfRenderWindow_display(gamecore.window);
        animation_bird(&duration, &image, &sprite);
        events(&gamecore, &sprite, &duration, &image);
        if (duration.life == 0) {
            sfMusic_destroy(gamecore.music);
            end_function(window);
        }
        re_initialisation(&gamecore, &sprite,
        &image, &duration);
    }
    return 0;
}

int main(void)
{
    sfRenderWindow *window = create_renderwindow(1920, 1080, 32, "my_hunter");
    sfEvent menu;
    sfTexture *menu_texture =
    sfTexture_createFromFile("./ressources/start_menu.png", NULL);
    sfSprite *menu_sprite = sfSprite_create();
    sfTexture *click_to_start_texture =
    sfTexture_createFromFile("./ressources/click_to_start.png", NULL);
    sfSprite *click_to_start_sprite = sfSprite_create();
    sfVector2f pos_click_to_start = {680, 400};
    sfSprite_setTexture(menu_sprite, menu_texture, sfTrue);
    initialisation_start(click_to_start_sprite,
    click_to_start_texture ,pos_click_to_start);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &menu)) {
            event3(window, menu);
        }
        start_reinitialisation(window, menu_sprite, click_to_start_sprite);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
