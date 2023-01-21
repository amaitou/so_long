/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:43 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/21 22:56:29 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **ag)
{
    t_map map;

    (void)ac;
    if (ac == 2)
    {
        map.pathfile = ag[1];
        if (ft_path_file(map.pathfile))
        {
            ft_map_parsing(&map);
            if (ft_map_checking(&map))
                ft_printf("Map Is Valid\n");
        }
        else
            ft_error("[!] The Path of The Map Is Invalid");
    }
    else
        ft_error("[!] Missing Arguments Or Too Many Arguments Have Been Set");
    return (0);
}