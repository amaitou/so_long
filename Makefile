
NAME = so_long
CC = cc
CFLAGS = -Wextra -Wall -Werror
CFILES = mandatory/ft_comp_checker.c \
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
		 mandatory/ft_check_path.c

#OBJS = $(CFILES:mandatory/%.c=mandatory/%.o)
SUPERLIB_DIR = ./superlib
SUPERLIB = ./superlib/superlib.a

# mandatory/%.o: mandatory/%.c
# 	@echo "\033[0;33m[*] compiling $?\033[0m"
# 	@$(CC) $(CFLAGS) -c $?

all: $(SUPERLIB) $(NAME)

# compile the super lib first
$(SUPERLIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB_DIR)


$(NAME):
	@@echo "\033[95m[.] output *.c to so_long\033[0m"
	@$(CC) $(CFLAGS) $(CFILES) -lmlx -framework OpenGL -framework AppKit $(SUPERLIB) -o $@

clean:
	@echo "\033[1;31m[!] deleting so_long\033[0m"
	@$(MAKE) clean -C $(SUPERLIB_DIR)
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(SUPERLIB_DIR)

re: fclean all

.PHONY: all clean fclean re
