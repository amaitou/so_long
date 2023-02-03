/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:33:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/03 04:56:47 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	ft_fileimgs1(game);
	ft_fileimgs2(game);
	while (i < game->len)
	{
		j = 0;
		ft_putter(game, i, j);
		++i;
	}
}
