/*
** EPITECH PROJECT, 2022
** initialisation
** File description:
** initialisation
*/

#include "my.h"

int initialisation_sprite(sprite_t *sprite, image_t *image)
{
    image->scoreint = 0;
    image->textscore = "0";
    image->scale_wall.x = 0.5;
    image->scale_wall.y = 0.5;
    image->scale.x = 2;
    image->scale.y = 2;
    image->scale2.x = 2;
    image->scale2.y = 2;
    image->scale_text.x = 1.4;
    image->scale_text.y = 1.8;
    image->scale_score.x = 0.2;
    image->scale_score.y = 0.1;
    image->heart_scale.x = 0.2;
    image->heart_scale.y = 0.2;
    image->heart2_scale.x = 0.2;
    image->heart2_scale.y = 0.2;
    image->heart3_scale.x = 0.2;
    image->heart3_scale.y = 0.2;
    return 0;
}

int initialisation_sprite1(sprite_t *sprite, image_t *image)
{
    sprite->score_pos.x = 1500;
    sprite->score_pos.y = 850;
    sprite->text_pos.x = 1565;
    sprite->text_pos.y = 860;
    sprite->background_pos.x = 0;
    sprite->background_pos.y = 0;
    sprite->duck_pos.x = 0;
    sprite->duck_pos.y = 0;
    sprite->anya_react_pos.x = 1700;
    sprite->anya_react_pos.y = 800;
    sprite->heart_pos.x = 1800;
    sprite->heart_pos.y = 0;
    sprite->heart2_pos.x = 1700;
    sprite->heart2_pos.y = 0;
    sprite->heart3_pos.x = 1600;
    sprite->heart3_pos.y = 0;
    sprite->animation.height = 51;
    sprite->animation.left = 0;
    return 0;
}

int initialisation_sprite2(sprite_t *sprite, image_t *image)
{
    sprite->animation.top = 0;
    sprite->animation.width = 55;
    sprite->animation2.height = 84;
    sprite->animation2.left = 0;
    sprite->animation2.top = 0;
    sprite->animation2.width = 85;
    image->background_sprite = sfSprite_create();
    image->duck_sprite = sfSprite_create();
    image->anya_react_sprite = sfSprite_create();
    image->score_sprite = sfSprite_create();
    image->heart_sprite = sfSprite_create();
    image->heart2_sprite = sfSprite_create();
    image->heart3_sprite = sfSprite_create();
    image->heart_texture =
    sfTexture_createFromFile("ressources/life.png", NULL);
    image->heart2_texture =
    sfTexture_createFromFile("ressources/life.png", NULL);
    return 0;
}

int initialisation_sprite3(sprite_t *sprite, image_t *image)
{
    image->heart3_texture =
    sfTexture_createFromFile("ressources/life.png", NULL);
    image->score_texture =
    sfTexture_createFromFile("ressources/Squarepink.png", NULL);
    image->background_texture =
    sfTexture_createFromFile("ressources/Background.png", NULL);
    image->duck_texture =
    sfTexture_createFromFile("ressources/Anya_sprite.png", NULL);
    image->anya_react_texture =
    sfTexture_createFromFile("ressources/Anya_facial.png", NULL);
    image->score = sfText_create();
    sfSprite_setTexture(image->background_sprite,
    image->background_texture, sfFalse);
    sfSprite_setTexture(image->duck_sprite,
    image->duck_texture, sfFalse);
    sfSprite_setTexture(image->anya_react_sprite,
    image->anya_react_texture, sfFalse);
    sfSprite_setTexture(image->score_sprite,
    image->score_texture, sfFalse);
    return 0;
}

int initialisation_sprite4(sprite_t *sprite, image_t *image)
{
    sfSprite_setTexture(image->heart_sprite,
    image->heart_texture, sfFalse);
    sfSprite_setTexture(image->heart2_sprite,
    image->heart2_texture, sfFalse);
    sfSprite_setTexture(image->heart3_sprite,
    image->heart3_texture, sfFalse);
    sfSprite_setScale(image->duck_sprite, image->scale);
    sfSprite_setScale(image->anya_react_sprite, image->scale2);
    sfSprite_setScale(image->score_sprite, image->scale_score);
    sfSprite_setScale(image->background_sprite, image->scale_wall);
    sfSprite_setScale(image->heart_sprite, image->heart_scale);
    sfSprite_setScale(image->heart2_sprite, image->heart2_scale);
    sfSprite_setScale(image->heart3_sprite, image->heart3_scale);
    sfSprite_setPosition(image->background_sprite,
    sprite->background_pos);
    sfSprite_setPosition(image->score_sprite, sprite->score_pos);
    sfSprite_setPosition(image->duck_sprite, sprite->duck_pos);
    return 0;
}
