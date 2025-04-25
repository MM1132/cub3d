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
	$(SRC_DIR)/init_data.c \
	$(SRC_DIR)/render/minimap.c \
	$(SRC_DIR)/render/utils/put_rect.c \
	$(SRC_DIR)/vector/vector_new.c \
	$(SRC_DIR)/hooks/loop_key_hook.c \
	$(SRC_DIR)/garbage_collector/gc_exit.c \
	$(SRC_DIR)/garbage_collector/gc_add.c \
	$(SRC_DIR)/garbage_collector/gc_free.c \
	$(SRC_DIR)/garbage_collector/gc_init.c \
	$(SRC_DIR)/garbage_collector/gc_malloc.c \
	$(SRC_DIR)/garbage_collector/gc_utils.c \
	$(SRC_DIR)/garbage_collector/safe_functions/safe_split.c \
	$(SRC_DIR)/garbage_collector/safe_functions/safe_gnl.c \
	$(SRC_DIR)/map_validation/map_validation.c \
	$(SRC_DIR)/map_validation/validation_utils.c \
	$(SRC_DIR)/map_validation/create_map.c 

TOTAL_SRC_FILES := $(words $(SRC_FILES))
COMPILED_FILES_COUNT = 0

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)
	@echo "Cub3D Compilation Finished!"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42_A):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build > /dev/null 2>&1
	@cmake --build $(MLX42_DIR)/build -j4 2>&1 | \
	while IFS= read -r line; do \
		percentage=$$(echo "$$line" | perl -ne 'if (m/(?<=\[)\s*(\d+)(?!.*Linking C static)/) {print "$$1"}'); \
		if [ -n "$$percentage" ]; then \
			bash ./lib/libft/loading_bar.sh "MLX42 " 100 $$percentage; \
		fi \
	done


$(NAME): $(OBJ_FILES) finish_loading $(LIBFT_A) $(MLX42_A)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@bash ./lib/libft/loading_bar.sh "Cub3D " $(TOTAL_SRC_FILES) $(COMPILED_FILES_COUNT)
	@$(eval COMPILED_FILES_COUNT := $(shell echo $$(($(COMPILED_FILES_COUNT)+1))))

finish_loading:
	@bash ./lib/libft/loading_bar.sh "Cub3D " 100 100

# Other rules
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
