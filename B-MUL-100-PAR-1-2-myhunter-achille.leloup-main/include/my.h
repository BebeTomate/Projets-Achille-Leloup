/*
** EPITECH PROJECT, 2022
** header
** File description:
** my_h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Window/Export.h>

typedef struct image {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfTexture *duck_texture;
    sfSprite *duck_sprite;
    sfTexture *anya_react_texture;
    sfSprite *anya_react_sprite;
    sfTexture *score_texture;
    sfSprite *score_sprite;
    sfVector2f scale;
    sfVector2f scale2;
    sfVector2f scale_wall;
    sfVector2f scale_score;
    sfVector2f scale_text;
    char *textscore;
    sfText *score;
    int scoreint;
    sfTexture *heart_texture;
    sfSprite *heart_sprite;
    sfVector2f heart_scale;
    sfTexture *heart2_texture;
    sfSprite *heart2_sprite;
    sfVector2f heart2_scale;
    sfTexture *heart3_texture;
    sfSprite *heart3_sprite;
    sfVector2f heart3_scale;
} image_t;

typedef struct sprite {
    sfVector2f background_pos;
    sfVector2f duck_pos;
    sfVector2f anya_react_pos;
    sfVector2f score_pos;
    sfVector2f text_pos;
    sfVector2f heart_pos;
    sfVector2f heart2_pos;
    sfVector2f heart3_pos;
    sfIntRect animation;
    sfIntRect animation2;
} sprite_t;

typedef struct duration {
    sfClock *clock;
    sfClock *clock_wing;
    sfClock *clock_reaction;
    sfTime time_wing;
    sfTime time;
    sfTime time_react;
    float seconds;
    float seconds_wing;
    float seconds_react;
    int life;
} duration_t;

typedef struct gamecore {
    sfMusic *music;
    sfEvent event;
    sfVector2i click;
    sfRenderWindow *window;
}gamecore_t;

static sfRenderWindow * create_renderwindow(unsigned int x,
unsigned int y, unsigned int bpp, char *title);
int animation_bird(duration_t *duration,
image_t *image, sprite_t *sprite);
int events(gamecore_t *gamecore, sprite_t *sprite,
duration_t *duration, image_t *image);
int destroy_entities(gamecore_t *gamecore);
int initialisation_sprite(sprite_t *sprite, image_t *image);
int initialisation_sprite1(sprite_t *sprite, image_t *image);
int initialisation_sprite2(sprite_t *sprite, image_t *image);
int initialisation_sprite3(sprite_t *sprite, image_t *image);
int initialisation_sprite4(sprite_t *sprite, image_t *image);
int initialisation_music(gamecore_t *gamecore);
int initialisation_clock(duration_t *duration);
int re_initialisation(gamecore_t *gamecore,
sprite_t *sprite, image_t *image, duration_t *duration);
char *augment_score(int score);
int number_digits(int nb);
int if_press(sfRenderWindow *window);
int initialisation_all(gamecore_t *gamecore,
sprite_t *sprite, duration_t *duration, image_t *image);
int game_function(sfRenderWindow *window);
int initialisation_sprite5(sprite_t *sprite, image_t *image);
int event2(sfRenderWindow *window, sfEvent menu);
int event3(sfRenderWindow *window, sfEvent menu);
int end_reinitialisation(sfRenderWindow *window,
sfSprite *end_sprite, sfSprite *gameover_sprite);
int start_reinitialisation(sfRenderWindow *window,
sfSprite *menu_sprite, sfSprite *click_to_start_sprite);
int initialisation_start(sfSprite *click_to_start_sprite,
sfTexture *click_to_start_texture, sfVector2f pos_click_to_start);

#endif
