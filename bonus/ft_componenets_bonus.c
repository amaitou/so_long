/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_componenets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:25:46 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:55:00 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_contain(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

static void	ft_counter(t_game *game, char c, int i, int j)
{
	if (c == 'P')
	{
		game->plr.y = i;
		game->plr.x = j;
		game->plrs += 1;
	}
	else if (c == 'E')
	{
		game->ext.y = i;
		game->ext.x = j;
		game->exts += 1;
	}
	else if (c == 'C')
		game->cols += 1;
}

int	ft_check_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->len)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(ft_contain("PEC10", game->map[i][j])))
				return (0);
			ft_counter(game, game->map[i][j], i, j);
			++j;
		}
		++i;
	}
	if (game->plrs == 1 && game->cols >= 1 && game->exts == 1)
		return (1);
	return (0);
}

int	ft_check_rect(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = game->map[i];
	++i;
	while (i < game->len)
	{
		if (!(ft_strlen(line) == ft_strlen(game->map[i])))
			return (0);
		++i;
	}
	game->img.w = ft_strlen(line);
	game->img.h = game->len;
	return (1);
}

int	ft_check_walls(t_game *game)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (game->map[0][i] && game->map[game->len - 1][i])
	{
		if (!(game->map[0][i] == '1' && game->map[game->len - 1][i] == '1'))
			return (0);
		++i;
	}
	j = 1;
	while (j < game->len - 1)
	{
		l = ft_strlen(game->map[j]);
		if (!(game->map[j][0] == '1' && game->map[j][l - 1] == '1'))
			return (0);
		++j;
	}
	return (1);
}
