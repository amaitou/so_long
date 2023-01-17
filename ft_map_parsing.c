/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 17:44:04 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_map_parsing(t_map *mapping, char *path)
{
    int fd_1 = open(path, O_RDONLY);
    int fd_2 = open(path, O_RDONLY);
    int iterator_1 = 0;
    int iterator_2 = 0;
    if (fd_1 == -1 || fd_2 == -1)
        ft_error("Failed to open the map file");
    while (get_next_line(fd_1))
        ++iterator_1;
    mapping->map = malloc(sizeof(char **) * (iterator_1 + 1));
    if (!mapping->map)
        ft_error("Failed allocating the map");
    iterator_2 = 0;
    while (iterator_2 <= iterator_1)
    {
        mapping->map[iterator_2] = get_next_line(fd_2);
        ++iterator_2;
    }
    mapping->p = 0;
    mapping->c = 0;
    mapping->e = 0;
}