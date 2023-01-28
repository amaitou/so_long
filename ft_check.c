/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:58:50 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/28 01:31:56 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(t_game *game)
{
	if (!ft_path(game->path))
		ft_error("[!] Invalid Path File");
	if (ft_parse(game) == -1)
		ft_error("[!] Failed To Open The Map File");
	if (!ft_parse(game))
		ft_error("[!] The Map Ends With A New Line");
	ft_size(game);
	if (!ft_items(game))
		ft_error("[!] There Might Be Duplicated Or Missed Characters");
	if (ft_items(game) == -1)
		ft_error("[!] Weird Characters Included In The Map");
	if (!ft_rect(game))
		ft_error("[!] The Map Is Not Rectangular");
	return (1);
}
