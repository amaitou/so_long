/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:24 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/30 02:15:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **ag)
{
	t_game	game;

	if (ac == 2)
	{
		game.path = ag[1];
		ft_vars_init(&game);
		if (ft_checker(&game))
		{
			ft_mlx(&game);
			ft_render(&game);
			mlx_hook(game.mlx.win, 2, 0, ft_key_hook, &game);
			mlx_loop(game.mlx.mlx);
		}
	}
	return (0);
}
