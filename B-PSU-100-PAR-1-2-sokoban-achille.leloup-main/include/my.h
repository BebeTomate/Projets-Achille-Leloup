/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <ncurses.h>
    #include <curses.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>

typedef struct maps {
    int nblines;
    int *line_length;
    char **map;
    char *buffer;
    int P_x;
    int P_y;
    int nb_O;
    int count_P;
    int count_O;
    int count_X;
    int *O_x;
    int *O_y;
    int count_fill;
}map_t;

int *get_line_length(char *buffer, map_t *maps);
int get_nblines(char *buffer);
int store_array(map_t *maps);
int error_handling_all(map_t *maps);
int error_handling_buffer(map_t *maps, char element);
int movement_player(map_t *maps, int button);
int player_go_up(map_t *maps);
int player_go_down(map_t *maps);
int player_go_left(map_t *maps);
int player_go_right(map_t *maps);
int find_delivery(map_t *maps, int i, int j, int k);
int get_element_pos(map_t *maps, int i, int j, int k);
int free_all(map_t *maps);
int help_display(void);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int init_curse(void);
#endif /* !MY_H */
