/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:16:59 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 03:03:23 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_imgs(t_game *game)
{
	int	x;
	int	y;

	x = game->img.w * 50;
	y = game->img.h * 50;
	game->tex.col = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible.xpm", &x, &y);
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
	game->tex.bgd = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/wall.xpm", &x, &y);
	game->tex.wal = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/background.xpm", &x, &y);
	game->tex.ext = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/exit.xpm", &x, &y);
}

static void	ft_putter(t_game *game, void *win, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] == '1' || game->map[i][j] == 'C' ||
			game->map[i][j] == 'P' || game->map[i][j] == 'E' ||
			game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.bgd, j * 50, i * 50);
		if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.wal, j * 50, i * 50);
		if (game->map[i][j] == '0')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.bgd, j * 50, i * 50);
		if (game->map[i][j] == 'P')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.pl1, j * 50, i * 50);
		if (game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.ext, j * 50, i * 50);
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx.mlx, win,
				game->tex.col, j * 50, i * 50);
		++j;
	}
}

void	ft_render(t_game *game)
{
	int		i;
	int		j;
	void	*win;

	i = 0;
	win = game->mlx.win;
	ft_imgs(game);
	while (i < game->len)
	{
		j = 0;
		ft_putter(game, win, i, j);
		++i;
	}
}
