/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_rendering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:16:59 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/23 20:29:50 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_initial_images(t_game *game)
{
	int x = game->img.width * 50;
	int y = game->img.height * 50;
	game->img.collectible = 
		mlx_xpm_file_to_image(game->mlx.mlx, "./textures/collectible.xpm", &x, &y);
	game->img.player_1 = 
		mlx_xpm_file_to_image(game->mlx.mlx, "./textures/player_right.xpm", &x, &y);
	game->img.background = 
		mlx_xpm_file_to_image(game->mlx.mlx, "./textures/wall.xpm", &x, &y);
	game->img.wall = 
		mlx_xpm_file_to_image(game->mlx.mlx, "./textures/background.xpm", &x, &y);
	game->img.exit = 
		mlx_xpm_file_to_image(game->mlx.mlx, "./textures/exit.xpm", &x, &y);
}

void ft_set_images_to_windows(t_game *game)
{
	int	i;
	int	j;
	int maplen = ft_map_size(game);

	i = 0;
	ft_initial_images(game);
	while (i < maplen)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' || game->map[i][j] == 'C' || game->map[i][j] == 'P' || game->map[i][j] == 'E' || game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.background, j * 50, i * 50);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.wall, j * 50, i * 50);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.background, j * 50, i * 50);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.player_1, j * 50, i * 50);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.exit, j * 50, i * 50);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->img.collectible, j * 50, i * 50);
			++j;
		}
		++i;
	}
}