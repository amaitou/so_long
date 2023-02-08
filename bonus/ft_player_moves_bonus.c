/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:36 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 19:12:37 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			ft_player_editer(game, y, x, 'r');
			game->moves++;
		}
		else if (game->map[y][x + 1] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game, "[*] You Won", G);
		}
		else if (game->map[y][x + 1] == 'M')
			ft_img_destroy(game, "[!] You Have Been Caught By The Enemy", R);
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
			ft_player_editer(game, y, x, 'l');
			game->moves++;
		}
		else if (game->map[y][x - 1] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game, "[*] You Won", G);
		}
		else if (game->map[y][x - 1] == 'M')
			ft_img_destroy(game, "[!] You Have Been Caught By The Enemy", R);
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
			ft_player_editer(game, y, x, 'u');
			game->moves++;
		}
		else if (game->map[y - 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game, "[*] You Won", G);
		}
		else if (game->map[y - 1][x] == 'M')
			ft_img_destroy(game, "[!] You Have Been Caught By The Enemy", R);
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
			ft_player_editer(game, y, x, 'd');
			game->moves++;
		}
		else if (game->map[y + 1][x] == 'E')
		{
			if (game->cols == 0)
				ft_img_destroy(game, "[*] You Won", G);
		}
		else if (game->map[y + 1][x] == 'M')
			ft_img_destroy(game, "[!] You Have Been Caught By The Enemy", R);
	}
	else
		game->plr.d = 'd';
}
