/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:38:14 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 23:27:09 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	worldlen(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		++i;
	return (i);
}

static void	ft_free_path(char **p)
{
	int	i;
	int	j;

	i = worldlen(p);
	j = 0;
	while (j < i)
	{
		free(p[j]);
		++j;
	}
	free(p);
}

int	ft_check_path(char *s)
{
	char	**p;
	int		i;

	p = ft_split(s, '.');
	i = worldlen(p);
	if (i >= 2)
	{
		if (ft_strcmp(p[i - 1], "ber") == 0)
		{
			ft_free_path(p);
			return (1);
		}
	}
	ft_free_path(p);
	return (0);
}
