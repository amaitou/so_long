/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:07 by amait-ou          #+#    #+#             */
/*   Updated: 2023/01/29 04:39:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./superlib/superlib.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_textures
{
	void	*col;
	void	*wal;
	void	*pl1;
	void	*pl2;
	void	*pl3;
	void	*pl4;
	void	*ext;
	void	*bgd;
}	t_tex;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_player
{
	int		y;
	int		x;
	char	d;
}	t_plr;

typedef struct s_exit
{
	int	y;
	int	x;
}	t_ext;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	char		*path;
	int			cols;
	int			plrs;
	int			exts;
	int			len;
	char		**map;
	int			moves;
	t_tex		tex;
	t_img		img;
	t_plr		plr;
	t_ext		ext;
	t_mlx		mlx;
}	t_game;

void	ft_error(char *s);
int		ft_path(char *s);
int		ft_parse(t_game *game);
void	ft_init(t_game *game);
int		ft_check(t_game *game);
int		ft_comp(t_game *game);
int		ft_rect(t_game *game);
int		ft_walls(t_game *game);
int		ft_items(t_game *game);
void	ft_size(t_game *game);
void	ft_render(t_game *game);
void	ft_mlx(t_game *game);
int		ft_hook(int keycode, t_game *game);
void	ft_right(t_game *game);
void	ft_left(t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_destroy(t_game *game);
void	ft_cord(t_game *game, char c);
void	ft_alter(t_game *game, int y, int x, char c);

#endif