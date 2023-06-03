#include "../include/fdf.h"



/*
int ft_wordcount(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if(str == NULL)
        return (count);
    while (str[i])
    {
        if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
            count++;
        i++;
    }
    return (count);

}


void    ft_putstr(char *c)
{   
    if (c)
        while (*c)
            write(1, c++, 1);
}

int ft_width(char **character)
{
    int width;

    width = ft_wordcount(character[0], ' ');
    return (width);
}

char **str_data(int fd, int height, char *argv)
{
    int i;
    int width;
    char **character;
    char *line;
    char *result;

    result = (char *)1;
    i = 0;
    width = 0;
    fd = 0;
    line = NULL;
    character = malloc(sizeof(char *) * (height + 1));
    if (character == NULL)
        return (NULL);
    fd = open(argv, O_RDONLY);
    while(result)
{
    width = ft_strlen(get_next_line(fd));
    line[width] = '\0';
    character[i] = ft_strdup(line);
    free(line);
    i++;
}
    character[i] = NULL;
    close(fd);
    return (character);
}
*/