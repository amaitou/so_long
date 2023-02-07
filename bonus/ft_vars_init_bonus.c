/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:15:43 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 13:13:45 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_vars_init(t_game *game)
{
	game->img.w = 0;
	game->img.h = 0;
	game->plr.x = 0;
	game->plr.y = 0;
	game->plr.d = 'd';
	game->ext.on = 0;
	game->ext.y = 0;
	game->ext.y = 0;
	game->cols = 0;
	game->plrs = 0;
	game->exts = 0;
	game->moves = 1;
	game->enes = 0;
	game->ene.x = 0;
	game->ene.y = 0;
}
