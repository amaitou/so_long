
NAME = so_long_bonus
CC = cc
CFLAGS = -Wextra -Wall -Werror
CFILES = ft_check_path_bonus.c \
		 ft_checker_bonus.c \
		 ft_componenets_bonus.c \
		 ft_game_error_bonus.c \
		 ft_img_destroy_bonus.c \
		 ft_key_hook_bonus.c \
		 ft_map_parse_bonus.c \
		 ft_map_size_bonus.c \
		 ft_mlx_bonus.c \
		 ft_move_helpers_bonus.c \
		 ft_player_moves_bonus.c \
		 ft_putimg_bonus.c \
		 ft_render_bonus.c \
		 ft_vars_init_bonus.c \
		 ft_game_exit_bonus.c \
		 ft_free_bonus.c \
		 so_long_bonus.c

SOURCES = $(CFILES:.c=.o)
SUPERLIB = ../superlib
LIB = ../superlib/superlib.a

%.o: %.c
	@echo "\033[0;33m[*] compiling $?\033[0m"
	@$(CC) $(CFLAGS) -c $?

all: $(LIB) $(NAME)

$(LIB):
	@echo "\033[0;32m[+] making superlib\033[0m"
	@$(MAKE) -C $(SUPERLIB)

$(NAME): $(LIB) $(SOURCES)
	@$(CC) $(CFLAGS) $? -lmlx -framework OpenGL -framework AppKit $(LIB) -o $@ 

clean:
	@echo "\033[1;31m[!] deleting *.o\033[0m"
	@rm -f $(SOURCES)

fclean: clean
	@echo "\033[1;31m[!] deleting so_long *.o and \033[0m"
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(SUPERLIB)

re: fclean all

.PHONY: all clean fclean re
