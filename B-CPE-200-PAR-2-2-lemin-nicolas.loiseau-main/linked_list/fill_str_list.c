/*
** EPITECH PROJECT, 2023
** fill string
** File description:
** fill string in linked list
*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

void fill_str_list(list_t *list, char *str)
{
    list_t *stock = malloc(sizeof(list_t));
    list_t *current = list;
    stock->next = NULL;
    stock->str = str;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = stock;
    return;
}
