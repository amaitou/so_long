/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:43 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/18 14:55:21 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    t_map map;
    ft_map_parsing(&map, "./maps/map.ber");
    if (ft_map_checking(&map))
        ft_printf("Map is valid\n");
    ft_printf("width  -> %d\n", map.width);
    ft_printf("height -> %d\n", map.height);
    return (0);
}