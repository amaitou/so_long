/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:26:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 17:27:36 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == K_RIGHT || keycode == A_RIGHT)
		ft_right(game);
	else if (keycode == K_LEFT || keycode == A_LEFT)
		ft_left(game);
	else if (keycode == K_UP || keycode == A_UP)
		ft_up(game);
	else if (keycode == K_DOWN || keycode == K_DOWN)
		ft_down(game);
	else if (keycode == ESC)
		ft_destroy(game);
	ft_render(game);
	return (1);
}
