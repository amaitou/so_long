/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:07 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/21 20:38:12 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./superlib/includes/superlib.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_exit
{
	int	y;
	int	x;
}	t_exit;

typedef struct s_map
{
	char		*pathfile;
	int			collectibles;
	int			players;
	int			exits;
	char		**map;
	t_img		img;
	t_player	player;
	t_exit		exit;
}	t_map;

void	ft_error(char *s);
void	ft_map_parsing(t_map *smap);
int		ft_map_checking(t_map *smap);
int		ft_map_size(t_map *smap);
int		ft_check_components(t_map *smap);
int		ft_check_walls(t_map *smap);
int		ft_check_lens(t_map *smap);
void	ft_map_coordonates(t_map *smap);
int		ft_path_file(char *s);

#endif
