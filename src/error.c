#include "../include/fdf.h"

void    ft_exit_no_file(char *argv)
{
    ft_putstr(argv);
    ft_putstr(" No file loaded");
    exit(EXIT_FAILURE);
}

void    ft_exit(char *str)
{
    ft_putstr(str);
    exit(EXIT_FAILURE);
}
/*
void   ft_exit_dir(char *argv)
{
    ft_putstr("error: ");
    perror(argv); // produce a message on standard error describing the last error encountered during a call to a system or library function
    exit(EXIT_FAILURE);
}

void invalid_file_msg(int ft_return, char *argv)
{
    if (ft_return == 0)
        ft_exit("empty file\n");
    if (ft_return == -1)
        ft_exit_dir(argv);
}
*/