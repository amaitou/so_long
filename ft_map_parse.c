/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/30 23:45:21 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_ends(char *s)
{
	int	strlen;

	strlen = ft_strlen(s);
	if (s[strlen - 1] == '\n')
		return (1);
	return (0);
}

int	ft_map_parse(t_game *game)
{
	int		fd;
	char	*lines;
	char	*line;

	lines = NULL;
	fd = open(game->path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines = ft_strjoin(lines, line);
		line = get_next_line(fd);
	}
	if (ft_ends(lines))
		return (0);
	game->map = ft_split(lines, '\n');
	free(lines);
	close(fd);
	return (1);
}
