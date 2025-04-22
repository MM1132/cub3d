LIB_DIR := lib
SRC_DIR := src
OBJ_DIR := obj
CC := cc
CFLAGS := -Wall -Wextra -Werror -Wshadow

# Libft
LIBFT_DIR := $(LIB_DIR)/libft
LIBFT_A := $(LIBFT_DIR)/libft.a

# MLX42
MLX42_DIR := $(LIB_DIR)/MLX42
MLX42_A := $(MLX42_DIR)/build/libmlx42.a

LIBS := $(LIBFT_A) $(MLX42_A) -ldl -lglfw -lpthread -lm
IFLAGS := -Iinclude -I$(LIBFT_DIR)/include -I$(MLX42_DIR)/include/MLX42

# Executable setup
NAME := cub3D
SRC_FILES := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/garbage_collector/gc_exit.c \
	$(SRC_DIR)/garbage_collector/gc_add.c \
	$(SRC_DIR)/garbage_collector/gc_free.c \
	$(SRC_DIR)/garbage_collector/gc_init.c \
	$(SRC_DIR)/garbage_collector/gc_malloc.c \
	$(SRC_DIR)/garbage_collector/gc_utils.c

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42_A):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4

$(NAME): $(OBJ_FILES) $(LIBFT_A) $(MLX42_A)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Other rules
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(MLX42_DIR)/build
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
