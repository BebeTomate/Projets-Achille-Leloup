/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** strdup
*/

#include <stdlib.h>

#include "../../include/my.h"

char *my_strdup(char *str)
{
    int i;
    char *str2 = malloc(sizeof(char) * my_strlen(str) + 1);

    for (i = 0; str[i] != '\0'; i++) {
        str2[i] = str[i];
    }
    str2[i] = '\0';
    return (str2);
}
