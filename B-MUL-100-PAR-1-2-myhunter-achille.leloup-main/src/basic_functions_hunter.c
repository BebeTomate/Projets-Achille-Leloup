/*
** EPITECH PROJECT, 2022
** basic_function
** File description:
** basic
*/

#include "my.h"

int if_press(sfRenderWindow *window)
{
    int check;
    sfBool space_key = sfKeyboard_isKeyPressed(sfKeySpace);
    if (space_key)
        check = game_function(window);
    return 0;
}

int number_digits(int nb)
{
    int n = 1;
    int pos = 10;
    if (nb < 0) {
        nb = -nb;
    }
    while (nb >= pos) {
        n++;
        if (pos > 214748364) {
            break;
            }
        pos *= 10;
        }
    return (n);
}

char *augment_score(int score)
{
    int length = number_digits(score);
    char *result;
    result = malloc(sizeof(char) * length);
    result[length] = '\0';
    while (length--) {
        result[length] = score % 10 + '0';
        score /= 10;
        }
        return (result);
}

int event2(sfRenderWindow *window, sfEvent menu)
{
    if (menu.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int initialisation_music(gamecore_t *gamecore)
{
    gamecore->music =
    sfMusic_createFromFile("ressources/Anya_song.ogg");
    sfMusic_play(gamecore->music);
    sfMusic_setLoop(gamecore->music, sfTrue);
    return 0;
}
