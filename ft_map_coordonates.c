/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_coordonates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:36:26 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/21 18:47:19 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_map_coordonates(t_map *smap)
{
    int maplen;
    int iterator;
    char *line;
    int counter;

    maplen = ft_map_size(smap);
    iterator = 0;
    while (iterator < maplen)
    {
        counter = 0;
        line = smap->map[iterator];
        while (line[counter])
        {
            if (line[counter] == 'P')
            {
                smap->player.x = iterator;
                smap->player.y = counter;
            }
            else if (line[counter] == 'E')
            {
                smap->exit.x = iterator;
                smap->exit.y = counter;
            }
            counter++;
        }
        ++iterator;
    }
}