/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_destroy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:02:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:55:42 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_destroy(t_game *game, char *s, char *c)
{
	ft_printf("%s%s%s\n", c, s, W);
	ft_free(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(0);
}
