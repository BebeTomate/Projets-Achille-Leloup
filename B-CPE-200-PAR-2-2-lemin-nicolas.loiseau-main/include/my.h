/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_

    #include "struct.h"

void set_value(lemin_t *lemin);
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int size);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *str);
char *update_line(char *str);

#endif
