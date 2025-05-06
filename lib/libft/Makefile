CC=gcc
CFLAGS= -Wall -Wextra -Werror -Iinclude
NAME=libft.a
OBJ_DIR=obj

SRC_FILES=\
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf/ft_printf.c \
	ft_printf/get_format_specifier.c \
	ft_printf/put_hex.c \
	ft_printf/put_nbr_base.c \
	ft_printf/utils.c \
	ft_printf/print_functions/print_character_format.c \
	ft_printf/print_functions/print_hex_format.c \
	ft_printf/print_functions/print_nbr_format.c \
	ft_printf/print_functions/print_pointer_format.c \
	ft_printf/print_functions/print_string_format.c \
	ft_printf/print_functions/print_unsigned_format.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_isspace.c \
	ft_list_atoi.c \
	ft_sqrt.c \
	ft_isdigit_str.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstremoveone.c

TOTAL_SRC_FILES := $(words $(SRC_FILES))
COMPILED_FILES_COUNT = 0

# We create the list of .o files based on the list of .c files
OBJ_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# The compiled program depends on all the .o files
$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES_COUNT := $(shell echo $$(($(COMPILED_FILES_COUNT)+1))))
	@bash ./loading_bar.sh "Libft " $(TOTAL_SRC_FILES) $(COMPILED_FILES_COUNT) "\033[30m"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
