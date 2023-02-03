/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:55:45 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:56:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
		game->mlx.win = mlx_new_window(game->mlx.mlx, game->img.w * 50,
			game->img.h * 50, "so_long");
}
