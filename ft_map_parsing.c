/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/22 15:48:47 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_parsing(t_game *game)
{
	int	fd_1;
	int	fd_2;
	int	iterator_1;
	int	iterator_2;

	fd_1 = open(game->pathfile, O_RDONLY);
	fd_2 = open(game->pathfile, O_RDONLY);
	iterator_1 = 0;
	iterator_2 = 0;
	if (fd_1 == -1 || fd_2 == -1)
		ft_error("Failed to open the map file");
	while (get_next_line(fd_1))
		++iterator_1;
	game->map = malloc(sizeof(char **) * (iterator_1 + 1));
	if (!game->map)
		ft_error("Failed allocating the map");
	iterator_2 = 0;
	while (iterator_2 <= iterator_1)
	{
		game->map[iterator_2] = get_next_line(fd_2);
		++iterator_2;
	}
	game->players = 0;
	game->collectibles = 0;
	game->exits = 0;
	close(fd_1);
	close(fd_2);
}
