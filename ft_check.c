/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:58:50 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 01:08:36 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(t_game *game)
{
	if (!ft_path(game->path))
		ft_error("[!] Invalid Path File");
	if (!ft_parse(game))
		ft_error("[!] Failed To Open The Map File");
	ft_size(game);
	if (!ft_rect(game))
		ft_error("[!] The Map Is Not Rectangular");
	if (!ft_walls(game))
		ft_error("[!] The Map Is Not Surrounded By Walls");
	if (!ft_items(game))
		ft_error("[!] There Might Be Werid, Duplicated Or Missed Characters");
	return (1);
}
