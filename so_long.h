/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:07 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 17:48:01 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./superlib/includes/superlib.h"
# include <fcntl.h>

typedef struct s_map
{
    int c;
    int p;
    int e;
    char **map;
} t_map;

void ft_error(char *s);
void ft_map_parsing(t_map *mapping, char *path);
int ft_map_checking(t_map *mapping);
int ft_map_size(t_map *mapping);
int ft_check_components(t_map *mapping);
int ft_check_walls(t_map *mapping);
int ft_check_lens(t_map *mapping);

#endif
