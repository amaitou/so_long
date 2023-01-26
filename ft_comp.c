/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:25:46 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/26 16:48:38 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(ft_contain("PEC10", game->map[i][j])))
				return (-1);
			if (game->map[i][j] == 'P')
				game->plrs += 1;
			else if (game->map[i][j] == 'E')
				game->exts += 1;
			else if (game->map[i][j] == 'C')
				game->cols += 1;
			++j;
		}
		++i;
	}
	if (game->plrs == 1 && game->cols >= 1 && game->exts == 1)
		return (1);
	return (0);
}

int	ft_rect(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = game->map[i];
	++i;
	while (game->map[i])
	{
		if (!(ft_strlen(line) == ft_strlen(game->map[i])))
			return (0);
		++i;
	}
	return (1);
}
