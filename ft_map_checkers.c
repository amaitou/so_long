/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:46:02 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/23 16:33:59 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_components(t_game *game)
{
	int	iterator;

	iterator = 0;
	while (game->map[iterator])
	{
		game->collectibles += ft_charlen(game->map[iterator], 'C');
		game->players += ft_charlen(game->map[iterator], 'P');
		game->exits += ft_charlen(game->map[iterator], 'E');
		++iterator;
	}
	if (game->collectibles >= 1 && game->players == 1 && game->exits == 1)
		return (1);
	return (0);
}

int	ft_check_walls(t_game *game)
{
	int		counter_a;
	int		counter_b;
	char	*line;

	counter_a = 0;
	while (counter_a < ft_map_size(game))
	{
		counter_b = 0;
		line = game->map[counter_a];
		if (counter_a == 0)
		{
			while (line[counter_b] != '\n')
			{
				if (!(line[counter_b] == '1'))
					return (0);
				++counter_b;
			}
		}
		else if (counter_a + 1 == ft_map_size(game))
		{
			while (line[counter_b] != '\n')
			{
				if (!(line[counter_b] == '1'))
					return (0);
				++counter_b;
			}
		}
		else
		{
			if (!(line[counter_b] == '1'))
				return (0);
			counter_b++;
			while (line[counter_b] != '\n')
				counter_b++;
			counter_b--;
			if (!(line[counter_b] == '1'))
				return (0);
		}
		++counter_a;
	}
	return (1);
}

int	ft_check_lens(t_game *game)
{
	int		maplen;
	int		i;
	size_t	strlen;

	i = 0;
	maplen = ft_map_size(game);
	strlen = ft_strlen(game->map[i]);
	++i;
	while (i < maplen)
	{
		if (!(strlen == ft_strlen(game->map[i])))
			return (0);
		++i;
	}
	game->img.width = strlen - 1;
	game->img.height = maplen;
	return (1);
}
