/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:36 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 03:29:17 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_alter(t_game *game, int y, int x, char c)
{
	if (c == 'r')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->plr.x++;
		game->plr.d = 'r';
	}
	else if (c == 'l')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->plr.x--;
		game->plr.d = 'l';
	}
	else if (c == 'u')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->plr.y--;
		game->plr.d = 'u';
	}
	else if (c == 'd')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->plr.y++;
		game->plr.d = 'd';
	}
}

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
		}
		else if (game->map[y][x + 1] == 'E')
		{
			if (game->cols == 0)
				exit(0);
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
		}
		else if (game->map[y][x - 1] == 'E')
		{
			if (game->cols == 0)
				exit(0);
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
		}
		else if (game->map[y - 1][x] == 'E')
		{
			if (game->cols == 0)
				exit(0);
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
		}
		else if (game->map[y + 1][x] == 'E')
		{
			if (game->cols == 0)
				exit(0);
			ft_alter(game, y, x, 'd');
		}
	}
}
