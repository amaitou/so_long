/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:58:50 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/31 01:12:53 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checker(t_game *game)
{
	if (!ft_check_path(game->path))
		ft_game_error("[!] Invalid Path File");
	if (!ft_map_parse(game))
		ft_game_error("[!] Failed To Open The Map File");
	ft_map_size(game);
	if (!ft_check_rect(game))
	{
		ft_free(game);
		ft_game_error("[!] The Map Is Not Rectangular");
	}
	if (!ft_check_walls(game))
	{
		ft_free(game);
		ft_game_error("[!] The Map Is Not Surrounded By Walls");
	}
	if (!ft_check_items(game))
	{
		ft_free(game);
		ft_game_error("[!] There Might Be Weird, Duplicated Or Missed Chars");
	}
	return (1);
}
