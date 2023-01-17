/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 12:42:38 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_parsing(char *s)
{
    int fd_1 = open(s, O_RDONLY);
    int fd_2 = open(s, O_RDONLY);
    int iterator_1 = 0;
    int iterator_2 = 0;
    char **map;
    if (fd_1 == -1 || fd_2 == -1)
        ft_error("Failed to open the map file");
    while (get_next_line(fd_1))
        ++iterator_1;
    map = malloc(sizeof(char **) * (iterator_1 + 1));
    if (!map)
        ft_error("Failed allocating the map");
    iterator_2 = 0;
    while (iterator_2 <= iterator_1)
    {
        map[iterator_2] = get_next_line(fd_2);
        ++iterator_2;
    }
    return (map);
}