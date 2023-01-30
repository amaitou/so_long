/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:36 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/30 02:17:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->plr.x;
	y = game->plr.y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C' || game->map[y][x + 1] == '0')
		{
			if (game->map[y][x + 1] == 'C')
				game->cols--;
			game->ext.on = 0;
			ft_alter(game, y, x, 'r');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y][x + 1] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game);
		}
	}
	else
		game->plr.d = 'r';
}

void	ft_move_left(t_game *game)

{
	int	x;
	int	y;

	x = game->plr.x;
	y = game->plr.y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C' || game->map[y][x - 1] == '0')
		{
			if (game->map[y][x - 1] == 'C')
				game->cols--;
			game->ext.on = 0;
			ft_alter(game, y, x, 'l');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (x - 1 == game->ext.x && y == game->ext.y)
		{
			if (game->cols == 0)
				ft_img_destroy(game);
		}
	}
	else
		game->plr.d = 'l';
}

void	ft_move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->plr.x;
	y = game->plr.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C' || game->map[y - 1][x] == '0')
		{
			if (game->map[y - 1][x] == 'C')
				game->cols--;
			game->ext.on = 0;
			ft_alter(game, y, x, 'u');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y - 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game);
		}
	}
	else
		game->plr.d = 'u';
}

void	ft_move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->plr.x;
	y = game->plr.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C' || game->map[y + 1][x] == '0')
		{
			if (game->map[y + 1][x] == 'C')
				game->cols -= 1;
			game->ext.on = 0;
			ft_alter(game, y, x, 'd');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y + 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game);
		}
	}
	else
		game->plr.d = 'd';
}
