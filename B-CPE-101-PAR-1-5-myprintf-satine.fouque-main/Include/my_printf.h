/*
** EPITECH PROJECT, 2022
** my_print.h
** File description:
** printf
*/

#ifndef _MY_H_
    #define _MY_H_

    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>

int code_nb(int);
int if_nbr(int);
int my_strlen(char const *);
int my_put_nbr(int);
void my_putchar(char);
int my_putstr(char const *);
int o_printf(int);
int x_printf(int);
int grand_x_printf(int);
int u_printf(int);
int s_printf(char *);
int b_printf(int);
int my_put_nbr(int);
char *my_revstr(char *);
int switch_cases(const char *, va_list, char, int);
int switch_cases_bis(const char *format, va_list ap, char letter, int i);
int condition_letter(char l);
int found_letter(const char *, int);
int my_printf(const char *, ...);
int put_s_printf(char *, int);
int e_exp(char, int, int);
int e_neg(float, int);
int e_pos(float, int);
int e_printf(float, int);
int diese_flag(va_list, char, const char *, int);
int diese_flag_e(va_list, char, const char *, int);
int point_flag(va_list, char, const char *, int);
float if_f_printf(int, float, int, int);
float if_e_f_printf(int, float, int, int);
void f_printf(float, int, char);
int p_printf(void *);
float f_printf_bis(int, float);
int n_flag(char, va_list ap, int);
int plus_flag_float(va_list ap, char l, const char *format, int i);
int plus_flag_int(va_list ap, char l, const char *format, int i);
int count_digits_of_number(int nb);
int zero_flag(va_list ap, char letter, const char *format, int i);
int my_getnbr(char const *str, int j);
int g_printf(float dec, int nb, char g);
int display_g(int entier, char g, int nb);
int switch_cases3(const char *format, va_list ap, char letter, int i);
int g_printf_default(float rt, int nb, char g);
int switch_cases_flags(const char *format, int nb, char letter, int i);
int switch_cases_flags_bis(const char *format, float nb, char letter, int i);
int point_flag_plus(float nb, char letter, const char *format, int i);
int blank_flag(va_list ap, char letter, const char *format, int i);
int quote_flag(va_list ap, char l, const char *format, int i);
int minus_flag(va_list ap, char l, const char *format, int i);
int compteur(const char *format, int i, int comp);
int diese_flag_g(va_list ap, char letter, const char *format, int i);
int minus_str(va_list ap, char letter, const char *format, int i);
int minus_int(va_list ap, char letter, const char *format, int i);
int blank_str(va_list ap, char letter, const char *format, int i);
int blank_int(va_list ap, char letter, const char *format, int i);
int zero_int(va_list ap, char letter, const char *format, int i);
int display_f(int n, float temp);

#endif
