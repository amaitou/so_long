/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:07 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/17 12:42:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./superlib/includes/superlib.h"
# include <fcntl.h>

void ft_error(char *s);
char	**ft_map_parsing(char *s);
int ft_check_components(char **map);
int ft_check_walls(char **map);
int ft_map_len(char **map);
int ft_check_lens(char **map);

#endif
