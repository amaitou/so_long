
NAME = so_long
CC = cc
CFLAGS = -Wextra -Wall -Werror
CFILES = ft_check_path.c \
		 ft_checker.c \
		 ft_componenets.c \
		 ft_game_error.c \
		 ft_img_destroy.c \
		 ft_key_hook.c \
		 ft_map_parse.c \
		 ft_map_size.c \
		 ft_mlx.c \
		 ft_move_helpers.c \
		 ft_player_moves.c \
		 ft_putimg.c \
		 ft_render.c \
		 ft_vars_init.c \
		 ft_game_exit.c \
		 ft_free.c \
		 so_long.c

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
