/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:24 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 00:31:29 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **ag)
{
	t_game	game;

	if (ac == 2)
	{
		game.path = ag[1];
		ft_init(&game);
		if (ft_check(&game))
		{
			ft_mlx(&game);
			ft_render(&game);
			mlx_key_hook(game.mlx.win, ft_hook, &game);
			mlx_loop(game.mlx.mlx);
		}
	}
	return (0);
}
