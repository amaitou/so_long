/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_animation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:14:47 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 09:36:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_textures4(t_game *game)
{
	int	x;
	int	y;

	x = game->img.w * 50;
	y = game->img.h * 50;
	game->tex.co1 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_1.xpm", &x, &y);
	game->tex.co2 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_2.xpm", &x, &y);
	game->tex.co3 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_3.xpm", &x, &y);
	game->tex.co4 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_4.xpm", &x, &y);
}

void	ft_enemy_animation(t_game *game, int j, int i)
{
	if (game->col.c == 1)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co1, j, i);
	}
	if (game->col.c == 6)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co2, j, i);
	}
	if (game->col.c == 11)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co3, j, i);
	}
	if (game->col.c == 16)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co4, j, i);
	}
}

int	ft_collectible_animation(t_game *game)
{
	if (game->col.c == 16)
		game->col.c -= 16;
	game->col.c++;
	return (1);
}
