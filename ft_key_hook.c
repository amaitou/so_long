/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:26:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/30 02:17:08 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == K_RIGHT || keycode == A_RIGHT)
		ft_move_right(game);
	else if (keycode == K_LEFT || keycode == A_LEFT)
		ft_move_left(game);
	else if (keycode == K_UP || keycode == A_UP)
		ft_move_up(game);
	else if (keycode == K_DOWN || keycode == A_DOWN)
		ft_move_down(game);
	else if (keycode == ESC)
		ft_img_destroy(game);
	ft_render(game);
	return (1);
}
