/*
** EPITECH PROJECT, 2022
** UNIT TEST
** File description:
** UNIT TEST
*/

#include "../Include/my_printf.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, simple_string, .init = redirect_all_std)
{
    my_putstr("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_strlen, simple_str, .init = redirect_all_std)
{
    cr_assert_eq(my_strlen("123"), 3);
}

Test(my_putchar, simple_char, .init = redirect_all_std)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_put_nbr, nbr_lim_neg1, .init = redirect_all_std)
{
    my_put_nbr(-2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test(my_put_nbr, nbr_lim_neg2, .init = redirect_all_std)
{
    my_put_nbr(2147483647);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_put_nbr, normal_nbr, .init = redirect_all_std)
{
    my_put_nbr(123456);
    cr_assert_stdout_eq_str("123456");
}

Test(my_put_nbr, neg_nbr, .init = redirect_all_std)
{
    my_put_nbr(-123456);
    cr_assert_stdout_eq_str("-123456");
}

Test(my_revstr, reverse_str, .init = redirect_all_std)
{
    char str[6] = "Boule\0";
    my_revstr(str);
    cr_assert_str_eq(str, "eluoB");
}

Test(b_printf, binary_print, .init = redirect_all_std)
{
    b_printf(234);
    cr_assert_stdout_eq_str("11101010");
}

Test(b_printf, binary_print2, .init = redirect_all_std)
{
    cr_assert_eq(b_printf(-2), 84);
}

Test(if_nbr, condition_nb, .init = redirect_all_std)
{
    if_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(if_nbr, condition_nb1, .init = redirect_all_std)
{
    if_nbr(-23);
    cr_assert_stdout_eq_str("-23");
}

Test(if_nbr, condition_nb2, .init = redirect_all_std)
{
    if_nbr(24);
    cr_assert_stdout_eq_str("24");
}

Test(o_printf, octal_nb, .init = redirect_all_std)
{
    o_printf(23);
    cr_assert_stdout_eq_str("27");
}

Test(o_printf, octal_nb0, .init = redirect_all_std)
{
    o_printf(0);
    cr_assert_stdout_eq_str("0");
}

Test(x_printf, hexadecimal_nb1, .init = redirect_all_std)
{
    x_printf(43);
    cr_assert_stdout_eq_str("2b");
}

Test(x_printf, hexadecimal_nb2, .init = redirect_all_std)
{
    x_printf(40);
    cr_assert_stdout_eq_str("28");
}

Test(grand_x_printf, grandhexadecimal_nb1, .init = redirect_all_std)
{
    grand_x_printf(40);
    cr_assert_stdout_eq_str("28");
}

Test(grand_x_printf, grandhexadecimal_nb2, .init = redirect_all_std)
{
    grand_x_printf(43);
    cr_assert_stdout_eq_str("2B");
}

Test(u_printf, decimal_nb1, .init = redirect_all_std)
{
    u_printf(43);
    cr_assert_stdout_eq_str("43");
}

Test(u_printf, decimal_nb2, .init = redirect_all_std)
{
    u_printf(-43);
    cr_assert_stdout_eq_str("4294967253");
}

Test(s_printf, string1, .init = redirect_all_std)
{
    s_printf("BITCH");
    cr_assert_stdout_eq_str("BITCH");
}

Test(s_printf, string2, .init = redirect_all_std)
{
    cr_assert_eq(s_printf("BITCH"), 0);
}

Test(put_s_printf, put_string, .init = redirect_all_std)
{
    put_s_printf("AZIR\0", 2);
    cr_assert_stdout_eq_str("I\0");
}

Test(put_s_printf, put_string1, .init = redirect_all_std)
{
    put_s_printf("\aAZ", 0);
    cr_assert_stdout_eq_str("\\007");
}

Test(put_s_printf, put_string2, .init = redirect_all_std)
{
    char a[3];
    a[0] = 127;
    a[1] = 'A';
    a[2] = '\0';
    put_s_printf(a, 0);
    cr_assert_stdout_eq_str("\\177");
}

Test(condition_letter, condition_letter1, .init = redirect_all_std)
{
    cr_assert_eq(condition_letter('b'), 1);
}

Test(condition_letter, condition_letter2, .init = redirect_all_std)
{
    cr_assert_eq(condition_letter('Z'), -1);
}

Test(condition_letter, condition_letter3, .init = redirect_all_std)
{
    cr_assert_eq(condition_letter('+'), 0);
}

Test(found_letter, found_letter, .init = redirect_all_std)
{
    cr_assert_eq(found_letter("Il aime le jambon", 1), -1);
}

Test(count_digits_of_number, count_digits, .init = redirect_all_std)
{
    cr_assert_eq(count_digits_of_number(4322), 4);
}

Test(my_printf, myprintf1, .init = redirect_all_std)
{
    my_printf("%x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, myprintf2, .init = redirect_all_std)
{
    my_printf("%X", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, myprintf3, .init = redirect_all_std)
{
    my_printf("%u", -17);
    cr_assert_stdout_eq_str("4294967279");
}

Test(my_printf, myprintf4, .init = redirect_all_std)
{
    my_printf("%e", 123.0);
    cr_assert_stdout_eq_str("1.230000e+02");
}

Test(my_printf, myprintf6, .init = redirect_all_std)
{
    my_printf("%e", 0.0);
    cr_assert_stdout_eq_str("0.000000e+00");
}

Test(my_printf, myprintf7, .init = redirect_all_std)
{
    my_printf("%e", 123.23);
    cr_assert_stdout_eq_str("1.232300e+02");
}

Test(my_getnbr, get_number, .init = redirect_all_std)
{
    cr_assert_eq(my_getnbr("42 le meilleur nombre", 21), 42);
}

Test(my_getnbr, get_number1, .init = redirect_all_std)
{
    cr_assert_eq(my_getnbr("-42 le meilleur nombre", 22), -42);
}

Test(my_printf, myprintf8, .init = redirect_all_std)
{
    my_printf("%d", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, myprintf9, .init = redirect_all_std)
{
    my_printf("%s", "Bateau");
    cr_assert_stdout_eq_str("Bateau");
}

Test(my_printf, myprintf10, .init = redirect_all_std)
{
    my_printf("%s", "bateau");
    cr_assert_stdout_eq_str("bateau");
}

Test(my_printf, myprintf11, .init = redirect_all_std)
{
    my_printf("%i", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, myprintf12, .init = redirect_all_std)
{
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, myprintf16, .init = redirect_all_std)
{
    my_printf("%i", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, myprintf17, .init = redirect_all_std)
{
    my_printf("%g", 12.0);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, myprintf18, .init = redirect_all_std)
{
    my_printf("%g", -12.0);
    cr_assert_stdout_eq_str("-12");
}

Test(my_printf, myprintf19, .init = redirect_all_std)
{
    my_printf("%.1g", 12.0);
    cr_assert_stdout_eq_str("1e+01");
}

Test(my_printf, myprintf20, .init = redirect_all_std)
{
    my_printf("%012d", 12);
    cr_assert_stdout_eq_str("000000000012");
}

Test(my_printf, myprintf21, .init = redirect_all_std)
{
    my_printf("%''3d", 12);
    cr_assert_stdout_eq_str(" 12");
}

Test(my_printf, myprintf22, .init = redirect_all_std)
{
    my_printf("%''3s", "AHAH");
    cr_assert_stdout_eq_str("AHAH");
}

Test(dprintf, myprintf23, .init = redirect_all_std)
{
    dprintf(1,"%p", (void *)0x12345678);
    cr_assert_stdout_eq_str("0x12345678");
}

Test(my_printf, myprintf24, .init = redirect_all_std)
{
    my_printf("%i", 23);
    cr_assert_stdout_eq_str("23");
}

Test(my_printf, myprintf25, .init = redirect_all_std)
{
    my_printf("%+d", 12);
    cr_assert_stdout_eq_str("+12");
}

Test(my_printf, myprintf26, .init = redirect_all_std)
{
    my_printf("%-6d", 3);
    cr_assert_stdout_eq_str("3     ");
}

Test(my_printf, myprintf27, .init = redirect_all_std)
{
    my_printf("%+d", -3);
    cr_assert_stdout_eq_str("-3");
}

Test(my_printf, myprintf28, .init = redirect_all_std)
{
    my_printf("%-s", "AHAH");
    cr_assert_stdout_eq_str("AHAH");
}

Test(my_printf, myprintf29, .init = redirect_all_std)
{
    my_printf("%-4d", -3);
    cr_assert_stdout_eq_str("-3  ");
}

Test(code_nb, code_number, .init = redirect_all_std)
{
    code_nb(47483647);
    cr_assert_stdout_eq_str("47483647");
}
