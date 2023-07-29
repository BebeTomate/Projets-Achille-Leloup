/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"

int init_game(map_t *maps)
{
    maps->O_x = malloc(sizeof(int) * (maps->nb_O + 1));
    maps->O_y = malloc(sizeof(int) * (maps->nb_O + 1));
    int j;
    int k = 0;
    for (int i = 0; maps->map[i] != NULL ; i++) {
        j = 0;
        k = find_delivery(maps, i, j, k);
    }
    return 0;
}

int game_reset(map_t *maps)
{
    for (int i = 0; i < maps->nb_O; i++) {
        if (maps->map[maps->O_y[i]][maps->O_x[i]] != 'O' &&
        maps->map[maps->O_y[i]][maps->O_x[i]] == ' ') {
            maps->map[maps->O_y[i]][maps->O_x[i]] = 'O';
        }
        if (maps->map[maps->O_y[i]][maps->O_x[i]] == 'X')
            maps->count_fill++;
    }
    if (maps->count_fill != maps->nb_O)
        maps->count_fill = 0;
    if (maps->count_fill == maps->nb_O)
        return 1;
    return 0;
}

int my_popup(map_t *maps)
{
    int button;
    int map_length;
    init_curse();
    while (1) {
        clear();
        for (int i = 0; i < maps->nblines; i++) {
            map_length = my_strlen(maps->map[i]) / 2;
            mvprintw((LINES / 2) - maps->nblines + i,
            (COLS / 2) - map_length, maps->map[i]);
        }
        refresh();
        button = getch();
        movement_player(maps, button);
        if (game_reset(maps) == 1)
            break;
        if (button == 32)
            break;
    }
    endwin();
    return 0;
}

char *read_file(char const *filepath)
{
    int size;
    char *buffer = NULL;
    struct stat ap;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }
    if (stat(filepath, &ap) == -1) {
        return NULL;
    }
    size = ap.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    int rd = read(fd, buffer, size);
    if (rd == -1) {
        return NULL;
    }
    buffer[rd] = '\0';
    close(fd);
    return (buffer);
}

int main(int ac, char** av)
{
    map_t maps;
    if (ac = 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_display();
    char const *filepath = av[1];
    maps.buffer = read_file(filepath);
    if (maps.buffer == NULL)
        return 84;
    if (error_handling_all(&maps) == 84)
        return 84;
    maps.nblines = get_nblines(maps.buffer);
    maps.line_length = get_line_length(maps.buffer, &maps);
    maps.map = malloc(sizeof(char*) * (maps.nblines + 1));
    maps.map[maps.nblines] = NULL;
    maps.nb_O = 0;
    maps.count_fill = 0;
    store_array(&maps);
    init_game(&maps);
    my_popup(&maps);
    free_all(&maps);
    return 0;
}
