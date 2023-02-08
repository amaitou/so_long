/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:19 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 18:20:52 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_ends(char *s)
{
	int	strlen;
	int	i;

	strlen = ft_strlen(s);
	if (s[strlen - 1] == '\n' || s[0] == '\n')
		return (1);
	i = 1;
	while (i < strlen - 1)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int	ft_map_parse(t_game *game)
{
	char	*lines;
	char	*line;
	int		fd;

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
