/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:46:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 12:36:40 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_components(char **map)
{
    int c = 0;
    int p = 0;
    int e = 0;
    int iterator = 0;
    while (map[iterator])
    {
        c += ft_charlen(map[iterator], 'C');
        p += ft_charlen(map[iterator], 'P');
        e += ft_charlen(map[iterator], 'E');
        ++iterator;
    }
    if (c >= 1 && p == 1 && e == 1)
        return (1);
    return (0);
}

int ft_check_walls(char **map)
{
    int counter_a;
    int counter_b;
    char    *line;

    counter_a = 0;
    while (counter_a < ft_map_len(map))
    {
        counter_b = 0;
        line = map[counter_a];
        if (counter_a == 0)
        {
            while (line[counter_b] != '\n')
            {
                if (!(line[counter_b] == '1'))
                    return (0);
                ++counter_b;
            }
        }
        else if (counter_a + 1 == ft_map_len(map))
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

int ft_check_lens(char **map)
{
    int maplen = ft_map_len(map);
    int i = 0;
    size_t strlen = ft_strlen(map[i]);
    ++i;
    while (i < maplen)
    {
        if (!(strlen == ft_strlen(map[i])))
            return (0);
        ++i;
    }        
    return (1);
}

int ft_check_map(char **map)
{
    if (!ft_check_components(map))
        return (0);
    if (!ft_check_walls(map))
        return (0);
    if (!ft_check_lens(map))
        return (0);
    return (1);
}

int main(void)
{
    char **p = ft_map_parsing("./maps/map.ber");
    ft_printf("%d", ft_check_map(p));
    return (0);
}