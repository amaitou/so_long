/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:07 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/07 16:03:41 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../superlib/superlib.h"
# include <fcntl.h>
# include <mlx.h>

// Keyboard Keycodes
# define K_RIGHT 124
# define A_RIGHT 2
# define K_LEFT 123
# define A_LEFT 0
# define K_UP 126
# define A_UP 13
# define K_DOWN 125
# define A_DOWN 1
# define ESC 53

// String Colors
# define R "\x1B[31m"
# define B "\x1B[34m"
# define Y "\x1B[33m"
# define G "\x1B[32m" 
# define W "\x1B[37m"

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

// Path Checking
int		ft_check_path(char *s);

// Error Showing
void	ft_game_error(char *s);

// Map Parsing
int		ft_map_parse(t_game *game);

// Vars Initialization
void	ft_vars_init(t_game *game);

// Components Checking
int		ft_comp_checker(t_game *game);
int		ft_check_rect(t_game *game);
int		ft_check_walls(t_game *game);
int		ft_check_items(t_game *game);

// Map Size Counting
void	ft_map_size(t_game *game);

// Map Rendering
void	ft_game_render(t_game *game);
void	ft_textures1(t_game *game);
void	ft_textures2(t_game *game);
void	ft_texture_helper(t_game *game, void *img, int j, int i);
void	ft_textures3(t_game *game, int j, int i);
void	ft_put_textures(t_game *game, int i, int j);
void	ft_player_coordonates(t_game *game, char c);
void	ft_player_editer(t_game *game, int y, int x, char c);

// Mlx Initialization
void	ft_mlx_init(t_game *game);

// Mlx Hooks
int		ft_key_hook(int keycode, t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

// Image Destroying
void	ft_img_destroy(t_game *game, char *s, char *c);
int		ft_game_exit(t_game *game);
void	ft_map_free(t_game *game);

// Game Banner
void	ft_game_banner(void);

#endif