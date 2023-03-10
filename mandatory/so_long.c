/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:24 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 19:25:37 by amait-ou         ###   ########.fr       */
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
		if (ft_comp_checker(&game))
		{
			ft_game_banner();
			ft_mlx_init(&game);
			ft_game_render(&game);
			mlx_hook(game.mlx.win, 2, 0, ft_key_hook, &game);
			mlx_hook(game.mlx.win, 17, 0, ft_game_exit, &game);
			mlx_loop(game.mlx.mlx);
		}
	}
	ft_game_error("[!] Invalid Arguments ");
	return (0);
}
