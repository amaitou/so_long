/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smap_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:46:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:39 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_components(t_map *smap)
{
    int iterator = 0;
    while (smap->map[iterator])
    {
        smap->collectibles += ft_charlen(smap->map[iterator], 'C');
        smap->players += ft_charlen(smap->map[iterator], 'P');
        smap->exits += ft_charlen(smap->map[iterator], 'E');
        ++iterator;
    }
    if (smap->collectibles >= 1 && smap->players == 1 && smap->exits == 1)
        return (1);
    return (0);
}

int ft_check_walls(t_map *smap)
{
    int counter_a;
    int counter_b;
    char    *line;

    counter_a = 0;
    while (counter_a < ft_map_size(smap))
    {
        counter_b = 0;
        line = smap->map[counter_a];
        if (counter_a == 0)
        {
            while (line[counter_b] != '\n')
            {
                if (!(line[counter_b] == '1'))
                    return (0);
                ++counter_b;
            }
        }
        else if (counter_a + 1 == ft_map_size(smap))
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

int ft_check_lens(t_map *smap)
{
    int smaplen = ft_map_size(smap);
    int i = 0;
    size_t strlen = ft_strlen(smap->map[i]);
    ++i;
    while (i < smaplen)
    {
        if (!(strlen == ft_strlen(smap->map[i])))
            return (0);
        ++i;
    }
    smap->img.width = smaplen;
    smap->img.height = strlen;
    return (1);
}