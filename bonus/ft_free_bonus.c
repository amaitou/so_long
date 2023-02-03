/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:33:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:55:07 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			++i;
		}
	}
	free(game->map);
}
