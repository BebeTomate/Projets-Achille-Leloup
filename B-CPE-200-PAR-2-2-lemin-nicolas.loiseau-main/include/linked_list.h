/*
** EPITECH PROJECT, 2023
** linked list .h
** File description:
** linked list .h
*/

#ifndef _LINKED_LIST_H_
    #define _LINKED_LIST_H_

typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

void display_linked_list(list_t *list);
void free_linked_list(list_t *list);
void fill_str_list(list_t *list, char *str);

#endif
