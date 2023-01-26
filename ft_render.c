/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:16:59 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/26 17:56:04 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_imgs(t_game *game)
{
	int	x;
	int	y;

	x = game->img.width * 50;
	y = game->img.height * 50;
	game->img.collectible = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/collectible.xpm", &x, &y);
	game->img.player_1 = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/player_right.xpm", &x, &y);
	game->img.background = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/wall.xpm", &x, &y);
	game->img.wall = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/background.xpm", &x, &y);
	game->img.exit = mlx_xpm_file_to_image(
			game->mlx.mlx,
			"./textures/exit.xpm", &x, &y);
}

void	ft_render(t_game *game)
{
	int		i;
	int		j;
	void	*win;

	i = 0;
	win = game->mlx.mlx_win;
	ft_initial_imgs(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' || game->map[i][j] == 'C' ||
				game->map[i][j] == 'P' || game->map[i][j] == 'E' ||
				game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.background, j * 50, i * 50);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.wall, j * 50, i * 50);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.background, j * 50, i * 50);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.player_1, j * 50, i * 50);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.exit, j * 50, i * 50);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx.mlx, win,
					game->img.collectible, j * 50, i * 50);
			++j;
		}
		++i;
	}
}
