#include "fillit.h"

void       free_map(char **map)
{
    int     size;

    if (map != NULL)
    {
        size = ft_strlen(map[0]);
        while (size > 0)
        {
            ft_strdel(&map[size]);
            ft_putendl("Line freed!");
            --size;
        }
        /*free(&map);*/
        ft_putendl("Map freed!");
    }
}

void    solve(t_piece *head, int newlines, int max)
{
    static char    **map;
    int            ret;
    int            placed;
    
    placed = 0;
    map = initialize_map(newlines);
    ft_putendl("Sending to place_piece...");
    while (placed < max)
    {
        ret = place_piece(head, map, placed);
        if (ret == -1)
            break ;
        ++placed;
    }
    if (ret == -1)
    {
        free_map(map);
        solve(head, newlines + 5, max);
    }
    if (ret != -1)
        print_map(map);
}