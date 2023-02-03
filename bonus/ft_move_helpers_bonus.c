/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:32:01 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:56:22 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_cord(t_game *game, char c)
{
	if (c == 'r')
	{
		game->plr.x++;
		game->plr.d = 'r';
	}
	else if (c == 'l')
	{
		game->plr.x--;
		game->plr.d = 'l';
	}
	else if (c == 'u')
	{
		game->plr.y--;
		game->plr.d = 'u';
	}
	else if (c == 'd')
	{
		game->plr.y++;
		game->plr.d = 'd';
	}
}

void	ft_alter(t_game *game, int y, int x, char c)
{
	if (c == 'r')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		ft_cord(game, 'r');
	}
	else if (c == 'l')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		ft_cord(game, 'l');
	}
	else if (c == 'u')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		ft_cord(game, 'u');
	}
	else if (c == 'd')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		ft_cord(game, 'd');
	}
}
