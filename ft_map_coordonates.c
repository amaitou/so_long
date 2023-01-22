/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_coordonates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:36:26 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/22 15:48:31 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_coordonates(t_game *game)
{
	int		maplen;
	int		iterator;
	char	*line;
	int		counter;

	maplen = ft_map_size(game);
	iterator = 0;
	while (iterator < maplen)
	{
		counter = 0;
		line = game->map[iterator];
		while (line[counter])
		{
			if (line[counter] == 'P')
			{
				game->player.x = iterator;
				game->player.y = counter;
			}
			else if (line[counter] == 'E')
			{
				game->exit.x = iterator;
				game->exit.y = counter;
			}
			counter++;
		}
		++iterator;
	}
}
