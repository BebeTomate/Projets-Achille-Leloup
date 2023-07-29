/*
** EPITECH PROJECT, 2022
** basic_function
** File description:
** basic_function
*/

#include "my.h"

int *get_line_length(char *buffer, map_t *maps)
{
    int *line_length = malloc(sizeof(int) * (maps->nblines + 1));
    for (int j = 0; j < maps->nblines ; j++) {
        for (int i = 0; buffer[i] != '\n'; i++) {
            line_length[j]++;
        }
        line_length[j]++;
    }
    return (line_length);
}

int get_nblines(char* buffer)
{
    int nblines = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nblines++;
    }
    return (nblines + 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int nbc = 0;
    while (str[nbc] != '\0') {
        my_putchar(str[nbc]);
        nbc++;
    }
}

int my_strlen(char const *str)
{
    int nbcount = 0;
    while (str[nbcount] != '\0') {
        nbcount++;
    }
    return (nbcount);
}
