/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:06:27 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/08 19:32:43 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_exit(t_game *game)
{
	ft_printf("%s[!] You Have Exited The Game %s\n", R, W);
	ft_map_free(game->map);
	exit(0);
}
