/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** error_handling
*/
#include "my.h"

int error_handling_buffer(map_t *maps, char element)
{
    if (element == 'O')
        maps->count_O++;
    if (element == 'X')
        maps->count_X++;
    if (element == 'P')
        maps->count_P++;
    if (element != 32 && element != '\n' && element != '#'
    && element != 'X' && element != 'O' && element != 'P')
        return 84;
    return 0;
}

int error_handling_all(map_t *maps)
{
    int check = 0;
    for (int i = 0; maps->buffer[i]; i++) {
        check = error_handling_buffer(maps, maps->buffer[i]);
    }
    if (maps->count_P != 1)
        return 84;
    if (maps->count_O < maps->count_X)
        return 84;
    if (maps->count_O < 1 || maps->count_X < 1)
        return 84;
    if (check == 84)
        return 84;
    return check;
}

int help_display(void)
{
    my_putstr("USAGE\n     ");
    my_putstr("./my_sokoban map\n");
    my_putstr("DESCRIPTION\n     ");
    my_putstr("map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n      ");
    my_putstr("   'P' for the player, 'X' for boxes and 'O'");
    my_putstr("for storage locations.\n");
    return 0;
}

int init_curse(void)
{
    initscr();
    noecho();
    curs_set(false);
    keypad(stdscr, true);
}
