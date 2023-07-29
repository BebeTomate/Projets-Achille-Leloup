/*
** EPITECH PROJECT, 2022
** misc_function
** File description:
** function
*/

#include "my.h"

int re_initialisation(gamecore_t *gamecore,
sprite_t *sprite, image_t *image, duration_t *duration)
{
    sfSprite_setTextureRect(image->duck_sprite, sprite->animation);
    sfSprite_setTextureRect(image->anya_react_sprite, sprite->animation2);
    sfSprite_setPosition(image->duck_sprite, sprite->duck_pos);
    sfSprite_setPosition(image->anya_react_sprite, sprite->anya_react_pos);
    sfRenderWindow_drawSprite(gamecore->window, image->background_sprite, NULL);
    sfRenderWindow_drawSprite(gamecore->window, image->anya_react_sprite, NULL);
    sfRenderWindow_drawSprite(gamecore->window, image->score_sprite, NULL);
    sfRenderWindow_drawSprite(gamecore->window, image->heart_sprite, NULL);
    if (duration->life >= 2)
        sfRenderWindow_drawSprite(gamecore->window, image->heart2_sprite, NULL);
    if (duration->life == 3)
        sfRenderWindow_drawSprite(gamecore->window, image->heart3_sprite, NULL);
    sfRenderWindow_drawSprite(gamecore->window, image->duck_sprite, NULL);
    sfRenderWindow_drawText(gamecore->window, image->score, NULL);
    sfText_setString(image->score, image->textscore);
    sfText_setColor(image->score, sfBlack);
    sfText_setFont(image->score,
    sfFont_createFromFile("ressources/Starborn.ttf"));
    sfText_setPosition(image->score, sprite->text_pos);
    return 0;
}
