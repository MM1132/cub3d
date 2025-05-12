LIB_DIR := lib
SRC_DIR := src
OBJ_DIR := obj
CC := cc
CFLAGS := -Wall -Wextra -Werror -O1
# -g -fsanitize=address

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
	$(SRC_DIR)/collision_detection/collision_detection_utils.c \
	$(SRC_DIR)/collision_detection/circle_to_rect.c \
	$(SRC_DIR)/free_data/free_data.c \
	$(SRC_DIR)/rect/rect_new.c \
	$(SRC_DIR)/rect/rect_rotate.c \
	$(SRC_DIR)/rect/rect_get_bounds.c \
	$(SRC_DIR)/init/init_data.c \
	$(SRC_DIR)/init/init_player.c \
	$(SRC_DIR)/init/init_minimap.c \
	$(SRC_DIR)/init/init_inputs.c \
	$(SRC_DIR)/update/player_update.c \
	$(SRC_DIR)/update/player_movement.c \
	$(SRC_DIR)/update/minimap_update.c \
	$(SRC_DIR)/render/minimap/minimap_border.c \
	$(SRC_DIR)/render/minimap/minimap_utils.c \
	$(SRC_DIR)/render/minimap/minimap_rays.c \
	$(SRC_DIR)/render/minimap/minimap_grid.c \
	$(SRC_DIR)/render/minimap/minimap_player.c \
	$(SRC_DIR)/render/minimap/minimap.c \
	$(SRC_DIR)/render/utils/put_pixel_rotation.c \
	$(SRC_DIR)/render/utils/put_pixel.c \
	$(SRC_DIR)/render/utils/put_circle.c \
	$(SRC_DIR)/render/utils/put_fill.c \
	$(SRC_DIR)/render/utils/put_line.c \
	$(SRC_DIR)/render/utils/put_line_rotation.c \
	$(SRC_DIR)/render/utils/put_fill_rect.c \
	$(SRC_DIR)/render/utils/put_fill_rect_transform.c \
	$(SRC_DIR)/render/utils/put_rect.c \
	$(SRC_DIR)/render/utils/put_rect_rotation.c \
	$(SRC_DIR)/render/ray_cast/ray_cast.c \
	$(SRC_DIR)/render/ray_cast/ray_cast_utils.c \
	$(SRC_DIR)/render/world/world.c \
	$(SRC_DIR)/render/world/door.c \
	$(SRC_DIR)/render/overlay/crosshair.c \
	$(SRC_DIR)/render/overlay/help.c \
	$(SRC_DIR)/vector/vec_swap_xy.c \
	$(SRC_DIR)/vector/vec_product.c \
	$(SRC_DIR)/vector/vec_add.c \
	$(SRC_DIR)/vector/vec_length.c \
	$(SRC_DIR)/vector/vec_multiply_n.c \
	$(SRC_DIR)/vector/vec_new.c \
	$(SRC_DIR)/vector/vec_normalize.c \
	$(SRC_DIR)/vector/vec_rotate.c \
	$(SRC_DIR)/vector/vec_subtract.c \
	$(SRC_DIR)/vector/vec_subtract_to.c \
	$(SRC_DIR)/hooks/main_loop_hook.c \
	$(SRC_DIR)/hooks/scroll_hook.c \
	$(SRC_DIR)/hooks/mouse_hook.c \
	$(SRC_DIR)/hooks/cursor_hook.c \
	$(SRC_DIR)/hooks/resize_hook.c \
	$(SRC_DIR)/hooks/key_hook.c \
	$(SRC_DIR)/garbage_collector/gc_exit.c \
	$(SRC_DIR)/garbage_collector/gc_add.c \
	$(SRC_DIR)/garbage_collector/gc_free.c \
	$(SRC_DIR)/garbage_collector/gc_init.c \
	$(SRC_DIR)/garbage_collector/gc_malloc.c \
	$(SRC_DIR)/garbage_collector/gc_utils.c \
	$(SRC_DIR)/garbage_collector/safe_functions/safe_split.c \
	$(SRC_DIR)/garbage_collector/safe_functions/safe_gnl.c \
	$(SRC_DIR)/map_validation/map_utils.c \
	$(SRC_DIR)/map_validation/map_validation.c \
	$(SRC_DIR)/map_validation/validation_utils.c \
	$(SRC_DIR)/map_validation/create_map.c \
	$(SRC_DIR)/map_validation/create_map_utils.c \
	$(SRC_DIR)/map_validation/zeros_enclosed.c

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
			bash ./lib/libft/loading_bar.sh "MLX42 " 100 $$percentage "\033[37m"; \
		fi \
	done


$(NAME): $(OBJ_FILES) finish_loading $(LIBFT_A) $(MLX42_A)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@bash ./lib/libft/loading_bar.sh "Cub3D " $(TOTAL_SRC_FILES) $(COMPILED_FILES_COUNT) "\033[36m"
	@$(eval COMPILED_FILES_COUNT := $(shell echo $$(($(COMPILED_FILES_COUNT)+1))))

finish_loading:
	@bash ./lib/libft/loading_bar.sh "Cub3D " 100 100 "\033[36m"

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
