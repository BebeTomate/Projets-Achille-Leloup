/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** lemin
*/

#include <stdio.h>
#include <stdlib.h>

#include "include/my.h"
#include "include/linked_list.h"

int main(void)
{
    list_t *list = malloc(sizeof(list_t));
    char *str = NULL;
    size_t len = 0;

    while (getline(&str, &len, stdin) != -1) {
        if (str[0] == '#' && str[1] != '#') {
            continue;
        }
        str = update_line(str);
        fill_str_list(list, str);
        str = NULL;
        len = 0;
    }

    display_linked_list(list);
    free_linked_list(list);
    return (0);
}
