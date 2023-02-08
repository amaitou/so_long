/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_destroy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:02:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 19:38:34 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_destroy(t_game *game, char *s, char *c)
{
	ft_printf("%s%s%s\n", c, s, W);
	ft_map_free(game->map);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(0);
}
