/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:36 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 01:12:43 by amait-ou         ###   ########.fr       */
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
		if (game->map[y][x + 1] == 'C')
		{
			game->cols -= 1;
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->plr.x++;
		}
		else if (game->map[y][x + 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->plr.x++;
		}
		else if (game->map[y][x + 1] == 'E')
		{
			if (game->cols == 0)
				exit(0);
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->plr.x++;
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
		if (game->map[y][x - 1] == 'C')
		{
			game->cols -= 1;
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->plr.x--;
		}
		else if (game->map[y][x - 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->plr.x--;
		}
		else if (game->map[y][x - 1] == 'E')
		{
			if (game->cols == 0)
				exit(0);
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->plr.x--;
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
		if (game->map[y - 1][x] == 'C')
		{
			game->cols -= 1;
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->plr.y--;
		}
		else if (game->map[y - 1][x] == '0')
		{
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->plr.y--;
		}
		else if (game->map[y - 1][x] == 'E')
		{
			if (game->cols == 0)
				exit(0);
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->plr.y--;
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
		if (game->map[y + 1][x] == 'C')
		{
			game->cols -= 1;
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->plr.y++;
		}
		else if (game->map[y + 1][x] == '0')
		{
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->plr.y++;
		}
		else if (game->map[y + 1][x] == 'E')
		{
			if (game->cols == 0)
				exit(0);
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->plr.y++;
		}
	}
}

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == 124)
		ft_right(game);
	else if (keycode == 123)
		ft_left(game);
	else if (keycode == 126)
		ft_up(game);
	else if (keycode == 125)
		ft_down(game);
	ft_render(game);
	return (1);
}
