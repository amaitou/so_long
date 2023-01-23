/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:43 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/23 15:48:05 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **ag)
{
    t_game  game;

    (void)ac;
    game.pathfile = ag[1];
    ft_map_parsing(&game);
    if (ft_map_checking(&game))
    {
        game.mlx.mlx = mlx_init();
        game.mlx.mlx_win = mlx_new_window(game.mlx.mlx, game.img.width * 50, game.img.height * 50, "so_long");
        ft_set_images_to_windows(&game);
        mlx_loop(game.mlx.mlx);
    }
    return (0);
}