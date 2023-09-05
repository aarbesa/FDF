### COMPILATION ###
CC      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME = fdf
NAME_BONUS = fdfbonus

### INCLUDES ###

OBJ_PATH = objs
HEADER = includes
SRC_PATH = src
OBJ_PATH_BONUS = objs_bonus
HEADER_BONUS = includes_bonus
SRC_PATH_BONUS = src_bonus

MLX = mlx_linux

### SOURCE FILES ###

SOURCES =	libft/ft_split_fdf.c \
            libft/libft_functions.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c \
			main.c \
			fdf.c \
            free.c \
            image_creation.c \
			drawing_functs.c \
			map.c \

SOURCES_BONUS =	libft/ft_split_fdf.c \
            libft/libft_functions.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c \
			main.c \
			fdf.c \
            free.c \
			hooks_actions.c \
			hooks_movement.c \
			hooks_rotations.c \
            image_creation.c \
			drawing_functs.c \
			map.c \

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))
SRCS_BONUS = $(addprefix $(SRC_PATH_BONUS)/,$(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJ_PATH_BONUS)/,$(SOURCES_BONUS:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L ${MLX} -o $@ $^ -lmlx -lXext -lX11 -lm -lz
	@echo "$(GREEN)Project successfully compiled"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/*.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

bonus: mlx $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) -L ${MLX} -o $@ $^ -lmlx -lXext -lX11 -lm -lz
	@echo "$(GREEN)Project successfully compiled"

$(OBJ_PATH_BONUS)/%.o: $(SRC_PATH_BONUS)/%.c $(HEADER_BONUS)/*.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -f $(OBJ_PATH_BONUS)/*.o
	@rm -f $(OBJ_PATH)/*.o
	@rm -f $(OBJ_PATH_BONUS)/*/*.o
	@rm -f $(OBJ_PATH)/*/*.o

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -f $(OBJ_PATH_BONUS)/*.o
	@rm -f $(OBJ_PATH)/*.o
	@rm -f $(OBJ_PATH_BONUS)/*/*.o
	@rm -f $(OBJ_PATH)/*/*.o
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

mlx:
	@cd $(MLX) && $(MAKE)

re: fclean
	@$(MAKE) all

norminette:
	@norminette src/* src_bonus/* includes/* includes_bonus/*

.PHONY: re all fclean clean mlx norminette bonus
