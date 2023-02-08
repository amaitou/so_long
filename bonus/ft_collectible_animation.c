/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_animation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:14:47 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 11:00:42 by amait-ou         ###   ########.fr       */
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
	game->tex.co5 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_5.xpm", &x, &y);
}

void	ft_textures5(t_game *game)
{
	int	x;
	int	y;

	x = game->img.w * 50;
	y = game->img.h * 50;
	game->tex.co6 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_6.xpm", &x, &y);
	game->tex.co6 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_6.xpm", &x, &y);
	game->tex.co7 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_7.xpm", &x, &y);
	game->tex.co8 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_8.xpm", &x, &y);
	game->tex.co9 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible_9.xpm", &x, &y);
}

void	ft_enemy_animation_1(t_game *game, int j, int i)
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

void	ft_enemy_animation_2(t_game *game, int j, int i)
{
	if (game->col.c == 21)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co5, j, i);
	}
	if (game->col.c == 26)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co6, j, i);
	}
	if (game->col.c == 31)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co7, j, i);
	}
	if (game->col.c == 36)
	{
		ft_texture_helper(game, game->tex.bgd, j, i);
		ft_texture_helper(game, game->tex.co8, j, i);
	}
}

int	ft_collectible_animation(t_game *game)
{
	if (game->col.c == 36)
		game->col.c -= 36;
	game->col.c++;
	return (1);
}
