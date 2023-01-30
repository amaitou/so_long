
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
		 so_long.c
SOURCES = $(CFILES:.c=.o)
SUPERLIB = ./superlib
%.o: %.c
	@echo "compiling \033[1;32m$?\033[0m" 
	@$(CC) $(CFLAGS) -c $?

all: $(NAME)

$(NAME): $(SOURCES) $(LIB)
	@$(CC) $(CFLAGS) $? -lmlx -framework OpenGL -framework AppKit $(SUPERLIB)/superlib.a -o $@ 

$(LIB):
	$(MAKE) -s $(SUPERLIB)

clean:
	@echo "deleting *.c"
	@rm -f $(SOURCES)

fclean: clean
	@echo "deleting *.o"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
