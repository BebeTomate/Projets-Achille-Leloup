/*
** EPITECH PROJECT, 2023
** putstr
** File description:
** putstr
*/

#include <unistd.h>

#include "../../include/my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
    return;
}
