/*
** EPITECH PROJECT, 2022
** other
** File description:
** other
*/

#include "my.h"

int start_reinitialisation(sfRenderWindow *window,
sfSprite *menu_sprite, sfSprite *click_to_start_sprite)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, menu_sprite, NULL);
    sfRenderWindow_drawSprite(window, click_to_start_sprite, NULL);
    sfRenderWindow_display(window);
    if_press(window);
    return 0;
}

int end_reinitialisation(sfRenderWindow *window,
sfSprite *end_sprite, sfSprite *gameover_sprite)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, end_sprite, NULL);
    sfRenderWindow_drawSprite(window, gameover_sprite, NULL);
    sfRenderWindow_display(window);
}

int event3(sfRenderWindow *window, sfEvent menu)
{
    if (menu.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int initialisation_start(sfSprite *click_to_start_sprite,
sfTexture *click_to_start_texture, sfVector2f pos_click_to_start)
{
    sfSprite_setTexture(click_to_start_sprite, click_to_start_texture, sfTrue);
    sfSprite_setPosition(click_to_start_sprite, pos_click_to_start);
}

int initialisation_sprite5(sprite_t *sprite, image_t *image)
{
    sfSprite_setPosition(image->anya_react_sprite,
    sprite->anya_react_pos);
    sfSprite_setPosition(image->heart_sprite, sprite->heart_pos);
    sfSprite_setPosition(image->heart2_sprite, sprite->heart2_pos);
    sfSprite_setPosition(image->heart3_sprite, sprite->heart3_pos);
    sfText_setPosition(image->score, sprite->text_pos);
    sfText_setString(image->score, image->textscore);
    sfText_setColor(image->score, sfBlack);
    sfText_setFont(image->score,
    sfFont_createFromFile("ressources/Starborn.ttf"));
    sfText_scale(image->score, image->scale_text);
}
