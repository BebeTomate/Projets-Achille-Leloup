/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** strcat
*/

#include <stdlib.h>

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    char *str = malloc(sizeof(char) * my_strlen(dest) * my_strlen(src) + 1);
    int size = 0;
    for (int i = 0; dest[i] != '\0'; i++) {
        str[size] = dest[i];
        size++;
    }
    for (int i = 0; src[i] != '\0'; i++) {
        str[size] = src[i];
        size++;
    }
    str[size] = '\0';
    return (str);
}
