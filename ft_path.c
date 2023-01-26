/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:26:43 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/26 16:20:35 by amait-ou         ###   ########.fr       */
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

int	ft_path(char *s)
{
	char	**p;
	int		i;

	p = ft_split(s, '.');
	i = worldlen(p);
	if (ft_strcmp(p[i - 1], "ber") == 0)
		return (1);
	return (0);
}
