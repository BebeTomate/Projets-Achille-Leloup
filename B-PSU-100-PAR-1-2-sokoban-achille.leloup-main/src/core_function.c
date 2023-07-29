/*
** EPITECH PROJECT, 2022
** core
** File description:
** core_function
*/

#include "my.h"

int free_all(map_t *maps)
{
    free(maps->map);
    free(maps->O_x);
    free(maps->O_y);
    free(maps->buffer);
    free(maps->line_length);
}

int get_element_pos(map_t *maps, int i, int j, int k)
{
    for (j = 0; j < maps->line_length[i]; j++) {
        maps->map[i][j] = maps->buffer[k];
        if (maps->map[i][j] == 'P') {
            maps->P_x = j;
            maps->P_y = i;
        }
        if (maps->map[i][j] == 'O')
            maps->nb_O++;
        k++;
    }
    return k;
}

int store_array(map_t *maps)
{
    for (int i = 0; i < maps->nblines; i++) {
        maps->map[i] = malloc(sizeof(char) * (maps->line_length[i] + 1));
    }
    int j;
    int k = 0;
    for (int i = 0; maps->map[i] != NULL ; i++) {
        j = 0;
        k = get_element_pos(maps, i, j, k);
    }
}

int find_delivery(map_t *maps, int i, int j, int k)
{
    for (j = 0; j < maps->line_length[i]; j++) {
        if (maps->map[i][j] == 'O') {
            maps->O_x[k] = j;
            maps->O_y[k] = i;
            k++;
        }
    }
    return k;
}
