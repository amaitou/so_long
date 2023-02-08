
NAME = so_long
NAME_2 = so_long_bonus
CC = cc
CFLAGS = -Wextra -Wall -Werror
MANDATORY = mandatory/ft_comp_checker.c \
		 mandatory/ft_componenets.c \
		 mandatory/ft_game_error.c \
		 mandatory/ft_img_destroy.c \
		 mandatory/ft_key_hook.c \
		 mandatory/ft_map_parse.c \
		 mandatory/ft_map_size.c \
		 mandatory/ft_mlx_init.c \
		 mandatory/ft_player_helpers.c \
		 mandatory/ft_player_moves.c \
		 mandatory/ft_put_textures.c \
		 mandatory/ft_game_render.c \
		 mandatory/ft_vars_init.c \
		 mandatory/ft_game_exit.c \
		 mandatory/ft_map_free.c \
		 mandatory/so_long.c \
		 mandatory/ft_check_path.c \
		 mandatory/ft_game_banner.c \
		 mandatory/ft_path_finding.c

BONUS = bonus/ft_comp_checker_bonus.c \
		 bonus/ft_componenets_bonus.c \
		 bonus/ft_game_error_bonus.c \
		 bonus/ft_img_destroy_bonus.c \
		 bonus/ft_key_hook_bonus.c \
		 bonus/ft_map_parse_bonus.c \
		 bonus/ft_map_size_bonus.c \
		 bonus/ft_mlx_init_bonus.c \
		 bonus/ft_player_helpers_bonus.c \
		 bonus/ft_player_moves_bonus.c \
		 bonus/ft_put_textures_bonus.c \
		 bonus/ft_game_render_bonus.c \
		 bonus/ft_vars_init_bonus.c \
		 bonus/ft_game_exit_bonus.c \
		 bonus/ft_map_free_bonus.c \
		 bonus/so_long_bonus.c \
		 bonus/ft_check_path_bonus.c \
		 bonus/ft_enemy_hooks.c \
		 bonus/ft_collectible_animation.c \
		 bonus/ft_both_hooks.c \
		 bonus/ft_game_banner_bonus.c \
		 bonus/ft_path_finding_bonus.c

SUPERLIB_DIR = ./superlib
SUPERLIB = ./superlib/superlib.a

all: $(SUPERLIB) $(NAME)

# compile the super lib
$(SUPERLIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB_DIR)

# generate the executable file "so_long" (Mandatory part)
$(NAME):
	@echo "\033[95m[.] output *.c to so_long\033[0m"
	@$(CC) $(CFLAGS) $(MANDATORY) -lmlx -framework OpenGL -framework AppKit $(SUPERLIB) -o $@

# generate the executable file "so_long_bonus" (Bonus part)
$(NAME_2):
	@echo "\033[95m[.] output *.c to so_long_bonus\033[0m"
	@$(CC) $(CFLAGS) $(BONUS) -lmlx -framework OpenGL -framework AppKit $(SUPERLIB) -o $@

bonus: all $(NAME_2)

clean:
	@echo "\033[1;31m[!] deleting so_long\033[0m"
	@$(MAKE) clean -C $(SUPERLIB_DIR)
	@rm -f $(NAME) $(NAME_2)

fclean: clean
	@rm -f $(NAME) $(NAME_2)
	@$(MAKE) fclean -C $(SUPERLIB_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
