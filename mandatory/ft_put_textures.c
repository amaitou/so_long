/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:16:59 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 06:27:24 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_textures1(t_game *game)
{
	int	x;
	int	y;

	x = game->img.w * 50;
	y = game->img.h * 50;
	game->tex.col = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible.xpm", &x, &y);
	game->tex.wal = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/wall.xpm", &x, &y);
	game->tex.bgd = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/background.xpm", &x, &y);
	game->tex.ext = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/exit.xpm", &x, &y);
}

void	ft_textures2(t_game *game)
{
	int	x;
	int	y;

	x = game->img.w * 50;
	y = game->img.h * 50;
	game->tex.pl1 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/player_right.xpm", &x, &y);
	game->tex.pl2 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/player_left.xpm", &x, &y);
	game->tex.pl3 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/player_up.xpm", &x, &y);
	game->tex.pl4 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/player_down.xpm", &x, &y);
}

void	ft_texture_helper(t_game *game, void *img, int j, int i)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		img, j * 50, i * 50);
}

void	ft_textures3(t_game *game, int j, int i)
{
	if (game->plr.d == 'r')
		ft_texture_helper(game, game->tex.pl1, j, i);
	if (game->plr.d == 'l')
		ft_texture_helper(game, game->tex.pl2, j, i);
	if (game->plr.d == 'u')
		ft_texture_helper(game, game->tex.pl3, j, i);
	if (game->plr.d == 'd')
		ft_texture_helper(game, game->tex.pl4, j, i);
}

void	ft_put_textures(t_game *game, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] == '1' || game->map[i][j] == 'C' ||
			game->map[i][j] == 'P' || game->map[i][j] == 'E' ||
			game->map[i][j] == '1')
			ft_texture_helper(game, game->tex.bgd, j, i);
		if (game->map[i][j] == '1')
			ft_texture_helper(game, game->tex.wal, j, i);
		if (game->map[i][j] == '0')
			ft_texture_helper(game, game->tex.bgd, j, i);
		if (game->map[i][j] == 'P')
			ft_textures3(game, j, i);
		if (game->map[i][j] == 'E')
			ft_texture_helper(game, game->tex.ext, j, i);
		if (game->map[i][j] == 'C')
			ft_texture_helper(game, game->tex.col, j, i);
		++j;
	}
}
