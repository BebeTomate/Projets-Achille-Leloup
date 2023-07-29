/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** strcmp
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int size)
{
    int len = 1;
    int j = 0;
    int i = 0;

    while (s1[i] == s2[j] && len <= size) {
        if (s1[i] == '\0' || len == size) {
            return (0);
        }
        i++;
        j++;
        len++;
    }
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int j = 0;
    int i = 0;

    while (s1[i] == s2[j]) {
        if (s1[i] == '\0') {
            return (0);
        }
        i++;
        j++;
    }
    return (1);
}
