/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:36 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 04:41:13 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_game *game)
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
			ft_alter(game, y, x, 'r');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y][x + 1] == 'E')
		{
			if (game->cols == 0)
				ft_destroy(game);
			ft_alter(game, y, x, 'r');
		}
	}
}

void	ft_left(t_game *game)

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
			ft_alter(game, y, x, 'l');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y][x - 1] == 'E')
		{
			if (game->cols == 0)
				ft_destroy(game);
			game->map[y][x - 1] = 'E';
		}
	}
}

void	ft_up(t_game *game)
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
			ft_alter(game, y, x, 'u');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y - 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_destroy(game);
			ft_alter(game, y, x, 'u');
		}
	}
}

void	ft_down(t_game *game)
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
			ft_alter(game, y, x, 'd');
			ft_printf("[+] Move -> %d\n", game->moves++);
		}
		else if (game->map[y + 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_destroy(game);
			ft_alter(game, y, x, 'd');
		}
	}
}
