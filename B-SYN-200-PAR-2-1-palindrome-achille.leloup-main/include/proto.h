/*
** EPITECH PROJECT, 2023
** include/proto
** File description:
** fireplace
*/

#ifndef PROTO_H_
    #define PROTO_H_
    #include "struct.h"

//error_handling.c
int error_handling(int ac, char **av, struct palindrome *param);
//palindrome.c
int palindrome(struct palindrome *param);
int is_palindrome(int nb, int base);
//utils.c
void usage(void);
int check_nb(char *str);
int reverse_int(int nb, int base);
int is_palindrome(int nb, int base);

#endif
