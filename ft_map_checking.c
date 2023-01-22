/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:39:35 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/22 15:48:19 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_checking(t_game *game)
{
	if (!ft_check_components(game))
		ft_error("[!] Invalid Map Components");
	if (!ft_check_walls(game))
		ft_error("[!] Invalid Map Walls");
	if (!ft_check_lens(game))
		ft_error("[!] The Map Is Not Rectangular");
	return (1);
}
