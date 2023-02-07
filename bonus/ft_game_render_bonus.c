/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:33:55 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 11:14:28 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_game_render(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	ft_textures1(game);
	ft_textures2(game);
	while (i < game->len)
	{
		j = 0;
		ft_put_textures(game, i, j);
		++i;
	}
}
