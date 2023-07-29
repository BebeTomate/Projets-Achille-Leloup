/*
** EPITECH PROJECT, 2023
** display
** File description:
** display linked list
*/

#include <stdio.h>

#include "../include/linked_list.h"
#include "../include/my.h"

static int get_dash(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            return (1);
        }
    }
    return (0);
}

static void second_display(list_t *disp)
{
    my_putstr(disp->str);
    my_putchar('\n');
    disp = disp->next;
    while (disp != NULL && disp->str[0] != '#' && get_dash(disp->str) == 0) {
        my_putstr(disp->str);
        my_putchar('\n');
        disp = disp->next;
    }
    my_putstr("#tunnels\n");
    while (disp != NULL && disp->str[0] != '#') {
        my_putstr(disp->str);
        my_putchar('\n');
        disp = disp->next;
    }
    my_putstr("#moves\n");
}

void display_linked_list(list_t *list)
{
    list_t *disp = list->next;
    my_putstr("#number_of_ants\n");
    my_putstr(disp->str);
    my_putchar('\n');
    disp = disp->next;
    my_putstr("#rooms\n");
    while (disp != NULL && disp->str[0] != '#') {
        my_putstr(disp->str);
        my_putchar('\n');
        disp = disp->next;
    }
    my_putstr(disp->str);
    my_putchar('\n');
    disp = disp->next;
    while (disp != NULL && disp->str[0] != '#' && get_dash(disp->str) == 0) {
        my_putstr(disp->str);
        my_putchar('\n');
        disp = disp->next;
    }
    second_display(disp);
}
