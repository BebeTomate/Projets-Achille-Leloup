/*
** EPITECH PROJECT, 2022
** player_move
** File description:
** movement
*/

#include "my.h"

int movement_player(map_t *maps, int button)
{
    if (button == KEY_UP)
        player_go_up(maps);
    if (button == KEY_DOWN)
        player_go_down(maps);
    if (button == KEY_LEFT)
        player_go_left(maps);
    if (button == KEY_RIGHT)
        player_go_right(maps);
    return 0;
}

int player_go_up(map_t *maps)
{
    if (maps->map[maps->P_y - 1][maps->P_x] == 'X') {
        if (maps->map[maps->P_y - 2][maps->P_x] != '#' &&
        maps->map[maps->P_y - 2][maps->P_x] != 'X') {
            maps->map[maps->P_y][maps->P_x] = ' ';
            maps->P_y--;
            maps->map[maps->P_y][maps->P_x] = 'P';
            maps->map[maps->P_y - 1][maps->P_x] = 'X';
        }
    }
    if (maps->map[maps->P_y - 1][maps->P_x] == ' ' ||
    maps->map[maps->P_y - 1][maps->P_x] == 'O') {
        maps->map[maps->P_y][maps->P_x] = ' ';
        maps->P_y--;
        maps->map[maps->P_y][maps->P_x] = 'P';
    }
    return 0;
}

int player_go_down(map_t *maps)
{
    if (maps->map[maps->P_y + 1][maps->P_x] == 'X') {
        if (maps->map[maps->P_y + 2][maps->P_x] != '#' &&
        maps->map[maps->P_y + 2][maps->P_x] != 'X') {
            maps->map[maps->P_y][maps->P_x] = ' ';
            maps->P_y++;
            maps->map[maps->P_y][maps->P_x] = 'P';
            maps->map[maps->P_y + 1][maps->P_x] = 'X';
        }
    }
    if (maps->map[maps->P_y + 1][maps->P_x] == ' ' ||
    maps->map[maps->P_y + 1][maps->P_x] == 'O') {
        maps->map[maps->P_y][maps->P_x] = ' ';
        maps->P_y++;
        maps->map[maps->P_y][maps->P_x] = 'P';
    }
    return 0;
}

int player_go_left(map_t *maps)
{
    if (maps->map[maps->P_y][maps->P_x - 1] == 'X') {
        if (maps->map[maps->P_y][maps->P_x - 2] != '#' &&
        maps->map[maps->P_y][maps->P_x - 2] != 'X') {
            maps->map[maps->P_y][maps->P_x] = ' ';
            maps->P_x--;
            maps->map[maps->P_y][maps->P_x] = 'P';
            maps->map[maps->P_y][maps->P_x - 1] = 'X';
        }
    }
    if (maps->map[maps->P_y][maps->P_x - 1] == ' ' ||
    maps->map[maps->P_y][maps->P_x - 1] == 'O') {
        maps->map[maps->P_y][maps->P_x] = ' ';
        maps->P_x--;
        maps->map[maps->P_y][maps->P_x] = 'P';
    }
    return 0;
}

int player_go_right(map_t *maps)
{
    if (maps->map[maps->P_y][maps->P_x + 1] == 'X') {
        if (maps->map[maps->P_y][maps->P_x + 2] != '#' &&
        maps->map[maps->P_y][maps->P_x + 2] != 'X') {
            maps->map[maps->P_y][maps->P_x] = ' ';
            maps->P_x++;
            maps->map[maps->P_y][maps->P_x] = 'P';
            maps->map[maps->P_y][maps->P_x + 1] = 'X';
        }
    }
    if (maps->map[maps->P_y][maps->P_x + 1] == ' ' ||
    maps->map[maps->P_y][maps->P_x + 1] == 'O') {
        maps->map[maps->P_y][maps->P_x] = ' ';
        maps->P_x++;
        maps->map[maps->P_y][maps->P_x] = 'P';
    }
    return 0;
}
