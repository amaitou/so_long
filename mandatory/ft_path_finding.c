/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:23:33 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 19:48:08 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_copy_map(t_game *game)
{
	int		i;
	size_t	j;
	size_t	c;

	game->c_map = (char **)malloc(sizeof(char *) * (game->len + 1));
	i = 0;
	while (i < game->len)
	{
		j = ft_strlen(game->map[i]);
		c = 0;
		game->c_map[i] = (char *)malloc(sizeof(char) * (j + 1));
		while (c < j)
		{
			game->c_map[i][c] = game->map[i][c];
			++c;
		}
		game->c_map[i][c] = '\0';
		++i;
	}
	game->c_map[i] = NULL;
}

void	ft_fill_map(t_game *game, int y, int x)
{
	if (!(game->c_map[y][x + 1] == '1'))
	{
		game->c_map[y][x + 1] = '1';
		ft_fill_map(game, y, x + 1);
	}
	if (!(game->c_map[y][x - 1] == '1'))
	{
		game->c_map[y][x - 1] = '1';
		ft_fill_map(game, y, x - 1);
	}
	if (!(game->c_map[y + 1][x] == '1'))
	{
		game->c_map[y + 1][x] = '1';
		ft_fill_map(game, y + 1, x);
	}
	if (!(game->c_map[y - 1][x] == '1'))
	{
		game->c_map[y - 1][x] = '1';
		ft_fill_map(game, y - 1, x);
	}
}

int	ft_path_finding(t_game *game)
{
	int	i;

	i = 0;
	ft_copy_map(game);
	ft_fill_map(game, game->plr.y, game->plr.x);
	while (i < game->len)
	{
		if (ft_iscontain(game->c_map[i], 'E')
			|| ft_iscontain(game->c_map[i], 'C'))
		{
			ft_map_free(game->c_map);
			return (0);
		}
		++i;
	}
	ft_map_free(game->c_map);
	return (1);
}
