/*
** EPITECH PROJECT, 2023
** is digit
** File description:
** is a digit
*/

#include <stdlib.h>

#include "../include/my.h"

static char *delete_new_line(char *str)
{
    char *str2 = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; str[i] != '\n'; i++) {
        str2[i] = str[i];
    }
    return (str2);
}

static int not_good_line(char *str, int i)
{
    if (str[i + 1] == '#') {
        return (1);
    }
    return (0);
}

char *update_line(char *str)
{
    int j = 0;
    char *str2 = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; str[i] != '\n'; i++) {
        if (my_strncmp(str, "##", 2) == 0) {
            str2 = delete_new_line(str);
            return (str2);
        }
        if (not_good_line(str, i) == 1) {
            break;
        }
        str2[j] = str[i];
        j++;
    }
    return (str2);
}
