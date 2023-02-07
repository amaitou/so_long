/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:32:01 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 03:59:02 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_coordonates(t_game *game, char c)
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

void	ft_player_editer(t_game *game, int y, int x, char c)
{
	if (c == 'r')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		ft_player_coordonates(game, 'r');
	}
	else if (c == 'l')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		ft_player_coordonates(game, 'l');
	}
	else if (c == 'u')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		ft_player_coordonates(game, 'u');
	}
	else if (c == 'd')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		ft_player_coordonates(game, 'd');
	}
}
