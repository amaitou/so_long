/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:26:09 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 01:28:17 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hook(int keycode, t_game *game)
{
	if (keycode == 124 || keycode == 2)
		ft_right(game);
	else if (keycode == 123 || keycode == 0)
		ft_left(game);
	else if (keycode == 126 || keycode == 13)
		ft_up(game);
	else if (keycode == 125 || 1)
		ft_down(game);
	ft_render(game);
	return (1);
}
