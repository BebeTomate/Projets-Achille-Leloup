/*
** EPITECH PROJECT, 2023
** free list
** File description:
** free list
*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

void free_linked_list(list_t *list)
{
    for (list_t *disp = list; disp != NULL; disp = disp->next) {
        free(disp->str);
    }

    return;
}
