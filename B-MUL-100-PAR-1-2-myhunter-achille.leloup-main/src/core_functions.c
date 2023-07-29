/*
** EPITECH PROJECT, 2022
** core_functions
** File description:
** core_functions
*/

#include "my.h"

int animation_bird(duration_t *duration, image_t *image, sprite_t *sprite)
{
    duration->time = sfClock_getElapsedTime(duration->clock);
    duration->time_wing = sfClock_getElapsedTime(duration->clock_wing);
    duration->seconds_wing = duration->time_wing.microseconds / 10000000.0;
    duration->seconds = duration->time.microseconds / 1000000.0;
    if (duration->seconds_wing > 0.02) {
        sprite->animation.left = sprite->animation.left + 55;
        sfClock_restart(duration->clock_wing);
    }
    if (duration->seconds > 0.03) {
        sprite->duck_pos.x = sprite->duck_pos.x + 10;
        sfClock_restart(duration->clock);
    }
    if (sprite->animation.left == 165)
        sprite->animation.left = 0;
    if (sprite->duck_pos.x >= 1920) {
        duration->life--;
        sprite->duck_pos.x = 0;
        sprite->duck_pos.y = rand() % 930;
    }
    return 0;
}

int change_face(sprite_t *sprite, duration_t *duration)
{
    if (duration->seconds_react > 3) {
        sprite->anya_react_pos.x = 1700;
        sprite->animation2.left = 0;
        sfClock_restart(duration->clock_reaction);
    }
}

int press_mouse(gamecore_t *gamecore, sprite_t *sprite,
duration_t *duration, image_t *image)
{
    gamecore->click =
    sfMouse_getPositionRenderWindow(gamecore->window);
    if (gamecore->click.x >= sprite->duck_pos.x &&
    gamecore->click.x <= sprite->duck_pos.x + 110
    && gamecore->click.y >= sprite->duck_pos.y &&
    gamecore->click.y <= sprite->duck_pos.y + 100) {
        sprite->duck_pos.x = 0;
        sprite->duck_pos.y = rand() % 930;
        sprite->animation2.left = 67;
        sprite->anya_react_pos.x = 1650;
        image->scoreint++;
        image->textscore = augment_score(image->scoreint);
        change_face(sprite, duration);
        }
}

int events(gamecore_t *gamecore, sprite_t *sprite,
duration_t *duration, image_t *image)
{
    duration->time_react = sfClock_getElapsedTime(duration->clock_reaction);
    duration->seconds_react = duration->time_react.microseconds / 1000000.0;
    while (sfRenderWindow_pollEvent(gamecore->window, &gamecore->event)) {
        if (gamecore->event.type == sfEvtClosed)
            sfRenderWindow_close(gamecore->window);
        if (gamecore->event.type == sfEvtMouseButtonPressed) {
            press_mouse(gamecore, sprite, duration, image);
        }
    }
    return 0;
}

int initialisation_clock(duration_t *duration)
{
    duration->clock = sfClock_create();
    duration->clock_wing = sfClock_create();
    duration->clock_reaction = sfClock_create();
    duration->life = 3;
    return 0;
}
