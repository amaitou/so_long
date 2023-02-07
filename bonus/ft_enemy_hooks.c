/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:20:52 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 15:36:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_enemy_right(t_game *game)
{
	int	x;
	int	y;

	x = game->ene.x;
	y = game->ene.y;
	if (x - 1 <= 0)
		x += 1;
	if (!(game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'))
	{
		if (game->map[y][x - 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'M';
			game->ene.x -= 1;
		}
		else if (game->map[y][x - 1] == 'P')
			ft_img_destroy(game,
				"[!] You Have Been Caught By The Enemy", R);
	}
}

static void	ft_enemy_left(t_game *game)
{
	int	x;
	int	y;

	x = game->ene.x;
	y = game->ene.y;
	if (x + 1 >= (int)ft_strlen(game->map[y]))
			x -= 1;
	if (!(game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'))
	{
		if (game->map[y][x + 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'M';
			game->ene.x += 1;
		}
		else if (game->map[y][x + 1] == 'P')
			ft_img_destroy(game,
				"[!] You Have Been Caught By The Enemy", R);
	}
}

static void	ft_enemy_up(t_game *game)
{
	int	x;
	int	y;

	x = game->ene.x;
	y = game->ene.y;
	if (y + 1 >= game->len)
			y -= 1;
	if (!(game->map[y + 1][x] == '1' || game->map[y + 1][x] == 'E'))
	{
		if (game->map[y + 1][x] == '0')
		{
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'M';
			game->ene.y += 1;
		}
		else if (game->map[y + 1][x] == 'P')
			ft_img_destroy(game,
				"[!] You Have Been Caught By The Enemy", R);
	}
}

static void	ft_enemy_down(t_game *game)
{
	int	x;
	int	y;

	x = game->ene.x;
	y = game->ene.y;
	if (y - 1 <= 0)
		y += 1;
	if (!(game->map[y - 1][x] == '1' || game->map[y - 1][x] == 'E'))
	{
		if (game->map[y - 1][x] == '0')
		{
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'M';
			game->ene.y -= 1;
		}
		else if (game->map[y - 1][x] == 'P')
			ft_img_destroy(game,
				"[!] You Have Been Caught By The Enemy", R);
	}
}

int	ft_enemytextures(t_game *game)
{
	int	r;

	r = rand() % 100;
	if (r == 1)
		ft_enemy_right(game);
	else if (r == 2)
		ft_enemy_left(game);
	else if (r == 3)
		ft_enemy_up(game);
	else if (r == 4)
		ft_enemy_down(game);
	ft_game_render(game);
	return (1);
}
