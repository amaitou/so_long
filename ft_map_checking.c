/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:39:35 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 17:37:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_map_checking(t_map *mapping)
{
    if (!ft_check_components(mapping))
        ft_error("Error related to map components");    
    if (!ft_check_walls(mapping))
        ft_error("Error related to map walls");    
    if (!ft_check_lens(mapping))
        ft_error("Error related to map size");
    return (1);
}