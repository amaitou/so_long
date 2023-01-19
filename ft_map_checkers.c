/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:46:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/18 14:54:47 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_components(t_map *mapping)
{
    int iterator = 0;
    while (mapping->map[iterator])
    {
        mapping->c += ft_charlen(mapping->map[iterator], 'C');
        mapping->p += ft_charlen(mapping->map[iterator], 'P');
        mapping->e += ft_charlen(mapping->map[iterator], 'E');
        ++iterator;
    }
    if (mapping->c >= 1 && mapping->p == 1 && mapping->e == 1)
        return (1);
    return (0);
}

int ft_check_walls(t_map *mapping)
{
    int counter_a;
    int counter_b;
    char    *line;

    counter_a = 0;
    while (counter_a < ft_map_size(mapping))
    {
        counter_b = 0;
        line = mapping->map[counter_a];
        if (counter_a == 0)
        {
            while (line[counter_b] != '\n')
            {
                if (!(line[counter_b] == '1'))
                    return (0);
                ++counter_b;
            }
        }
        else if (counter_a + 1 == ft_map_size(mapping))
        {
            while (line[counter_b] != '\n')
            {
                if (!(line[counter_b] == '1'))
                    return (0);
                ++counter_b;
            }
        }
        else
        {
            if (!(line[counter_b] == '1'))
                return (0);
            counter_b++;
            while (line[counter_b] != '\n')
                counter_b++;
            counter_b--;
            if (!(line[counter_b] == '1'))
                return (0);
        }
        ++counter_a;
    }
    return (1);
}

int ft_check_lens(t_map *mapping)
{
    int maplen = ft_map_size(mapping);
    int i = 0;
    size_t strlen = ft_strlen(mapping->map[i]);
    ++i;
    while (i < maplen)
    {
        if (!(strlen == ft_strlen(mapping->map[i])))
            return (0);
        ++i;
    }
    mapping->height = maplen;
    mapping->width = strlen;
    return (1);
}