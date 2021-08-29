NAME := libft.a

# **************************************************************************** #

SRC_DIR := src

# **************************************************************************** #

COMPLEX_DIR := complex

COMPLEX_SRC := complex_abs.c \
               complex_add.c \
               complex_div.c \
               complex_init.c \
               complex_mul.c \
               complex_sub.c

COMPLEX_SRC := $(addprefix $(COMPLEX_DIR)/, $(COMPLEX_SRC))
COMPLEX_OBJ := $(COMPLEX_SRC:.c=.o)
COMPLEX_DEP := $(COMPLEX_SRC:.c=.d)

# **************************************************************************** #

CTYPE_DIR := ctype

CTYPE_SRC := ft_digittoint.c \
             ft_isalnum.c \
             ft_isalpha.c \
             ft_isascii.c \
             ft_isblank.c \
             ft_iscntrl.c \
             ft_isdigit.c \
             ft_isgraph.c \
             ft_islower.c \
             ft_isprint.c \
             ft_ispunct.c \
             ft_isspace.c \
             ft_isupper.c \
             ft_isxdigit.c \
             ft_tolower.c \
             ft_toupper.c

CTYPE_SRC := $(addprefix $(CTYPE_DIR)/, $(CTYPE_SRC))
CTYPE_OBJ := $(CTYPE_SRC:.c=.o)
CTYPE_DEP := $(CTYPE_SRC:.c=.d)

# **************************************************************************** #

LIST_DIR := list

LIST_SRC := list_free.c \
            list_init.c \
            list_pop_back.c \
            list_pop_front.c \
            list_push_back.c \
            list_push_front.c

LIST_SRC := $(addprefix $(LIST_DIR)/, $(LIST_SRC))
LIST_OBJ := $(LIST_SRC:.c=.o)
LIST_DEP := $(LIST_SRC:.c=.d)

# **************************************************************************** #

MATH_DIR := math

MATH_SRC := ft_fabs.c \
            ft_fabsf.c \
            ft_fabsl.c \
            ft_fmax.c \
            ft_fmaxf.c \
            ft_fmaxl.c \
            ft_fmin.c \
            ft_fminf.c \
            ft_fminl.c \
            ft_llmax.c \
            ft_llmin.c \
            ft_lmax.c \
            ft_lmin.c \
            ft_max.c \
            ft_min.c

MATH_SRC := $(addprefix $(MATH_DIR)/, $(MATH_SRC))
MATH_OBJ := $(MATH_SRC:.c=.o)
MATH_DEP := $(MATH_SRC:.c=.d)

# **************************************************************************** #

STDIO_DIR := stdio
PRINTF_DIR := printf

PRINTF_SRC := ft_printf.c \
              pf_bigint.c \
              pf_buffer.c \
              pf_handle_asterisk.c \
              pf_handle_bigfloat.c\
              pf_handle_bin.c \
              pf_handle_char.c \
              pf_handle_float.c \
              pf_handle_hex_lower.c \
              pf_handle_hex_upper.c \
              pf_handle_invalid.c \
              pf_handle_length.c \
              pf_handle_oct.c \
              pf_handle_percent.c \
              pf_handle_placeholder.c \
              pf_handle_pointer.c \
              pf_handle_rounding.c \
              pf_handle_signed.c \
              pf_handle_string.c \
              pf_handle_unsigned.c \
              pf_print_placeholder.c \
              pf_read_fields.c \
              pf_utils_1.c \
              pf_utils_2.c

PRINTF_SRC := $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC))

STDIO_SRC := ft_error.c \
             ft_putchar.c \
             ft_putchar_fd.c \
             ft_putendl.c \
             ft_putendl_fd.c \
             ft_putnbr.c \
             ft_putnbr_fd.c \
             ft_putstr.c \
             ft_putstr_fd.c \
             get_next_line.c \
             $(PRINTF_SRC)

STDIO_SRC := $(addprefix $(STDIO_DIR)/, $(STDIO_SRC))
STDIO_OBJ := $(STDIO_SRC:.c=.o)
STDIO_DEP := $(STDIO_SRC:.c=.d)

# **************************************************************************** #

STDLIB_DIR := stdlib

STDLIB_SRC := free_split.c \
              ft_abs.c \
              ft_atoi.c \
              ft_atol.c \
              ft_atoll.c \
              ft_intlen.c \
              ft_itoa.c \
              ft_labs.c \
              ft_llabs.c \
              ft_memalloc.c \
              ft_memdel.c \
              ft_qsort.c \
              ft_strdel.c \
              ft_strnew.c \
              ft_strtol.c \
              ft_strtoll.c \
              ft_swap.c \
              xcalloc.c \
              xmalloc.c

STDLIB_SRC := $(addprefix $(STDLIB_DIR)/, $(STDLIB_SRC))
STDLIB_OBJ := $(STDLIB_SRC:.c=.o)
STDLIB_DEP := $(STDLIB_SRC:.c=.d)

# **************************************************************************** #

STRING_DIR := string

STRING_SRC := ft_bzero.c \
              ft_memccpy.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_memcpy.c \
              ft_memdup.c \
              ft_memmove.c \
              ft_mempcpy.c \
              ft_memset.c \
              ft_stpcpy.c \
              ft_stpncpy.c \
              ft_strcasecmp.c \
              ft_strcat.c \
              ft_strchr.c \
              ft_strclr.c \
              ft_strcmp.c \
              ft_strcnt.c \
              ft_strcpy.c \
              ft_strdup.c \
              ft_strendswith.c \
              ft_strequ.c \
              ft_striter.c \
              ft_striteri.c \
              ft_strjmp.c \
              ft_strjoin.c \
              ft_strlcat.c \
              ft_strlcpy.c \
              ft_strlen.c \
              ft_strlower.c \
              ft_strmap.c \
              ft_strmapi.c \
              ft_strncasecmp.c \
              ft_strncat.c \
              ft_strncmp.c \
              ft_strncpy.c \
              ft_strndup.c \
              ft_strnequ.c \
              ft_strnlen.c \
              ft_strnstr.c \
              ft_strrchr.c \
              ft_strrev.c \
              ft_strsplit.c \
              ft_strstartswith.c \
              ft_strstr.c \
              ft_strsub.c \
              ft_strtrim.c \
              ft_strupper.c

STRING_SRC := $(addprefix $(STRING_DIR)/, $(STRING_SRC))
STRING_OBJ := $(STRING_SRC:.c=.o)
STRING_DEP := $(STRING_SRC:.c=.d)

# **************************************************************************** #

VECTOR_DIR := vector

VECTOR_SRC := vector_free.c \
              vector_get.c \
              vector_init.c \
              vector_pop_back.c \
              vector_push_back.c \
              vector_resize.c \
              vector_reverse.c \
              vector_set.c \
              vector_sort.c

VECTOR_SRC := $(addprefix $(VECTOR_DIR)/, $(VECTOR_SRC))
VECTOR_OBJ := $(VECTOR_SRC:.c=.o)
VECTOR_DEP := $(VECTOR_SRC:.c=.d)

# **************************************************************************** #

INC_DIRS := include \
            include/internal \
            include/internal/printf

# **************************************************************************** #

OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(COMPLEX_OBJ) \
                                $(CTYPE_OBJ) \
                                $(LIST_OBJ) \
                                $(MATH_OBJ) \
                                $(STDIO_OBJ) \
                                $(STDLIB_OBJ) \
                                $(STRING_OBJ) \
                                $(VECTOR_OBJ))

DEP := $(addprefix $(OBJ_DIR)/, $(COMPLEX_DEP) \
                                $(CTYPE_DEP) \
                                $(LIST_DEP) \
                                $(MATH_DEP) \
                                $(STDIO_DEP) \
                                $(STDLIB_DEP) \
                                $(STRING_DEP) \
                                $(VECTOR_DEP))

# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    CC := clang
endif

ifeq ($(UNAME_S), Linux)
    CC := gcc
endif

# **************************************************************************** #

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIRS)) \
          -MMD \
          -O2 -march=native -ftree-vectorize -pipe

# **************************************************************************** #

RESET   := \033[0;0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
WHITE   := \033[0;37m

# **************************************************************************** #

.PHONY: all clean fclean re

# **************************************************************************** #

all:
	@$(MAKE) $(NAME)

# **************************************************************************** #

$(NAME): $(OBJ)
	@printf "$(BLUE)"
	ar -cr $@ $?
	ranlib $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(COMPLEX_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(COMPLEX_DIR)/%.o: $(SRC_DIR)/$(COMPLEX_DIR)/%.c | $(OBJ_DIR)/$(COMPLEX_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(CTYPE_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(CTYPE_DIR)/%.o: $(SRC_DIR)/$(CTYPE_DIR)/%.c | $(OBJ_DIR)/$(CTYPE_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(LIST_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(LIST_DIR)/%.o: $(SRC_DIR)/$(LIST_DIR)/%.c | $(OBJ_DIR)/$(LIST_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(MATH_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(MATH_DIR)/%.o: $(SRC_DIR)/$(MATH_DIR)/%.c | $(OBJ_DIR)/$(MATH_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(STDIO_DIR)/$(PRINTF_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(STDIO_DIR)/$(PRINTF_DIR)/%.o: $(SRC_DIR)/$(STDIO_DIR)/$(PRINTF_DIR)/%.c | $(OBJ_DIR)/$(STDIO_DIR)/$(PRINTF_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

$(OBJ_DIR)/$(STDIO_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(STDIO_DIR)/%.o: $(SRC_DIR)/$(STDIO_DIR)/%.c | $(OBJ_DIR)/$(STDIO_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(STDLIB_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(STDLIB_DIR)/%.o: $(SRC_DIR)/$(STDLIB_DIR)/%.c | $(OBJ_DIR)/$(STDLIB_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(STRING_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(STRING_DIR)/%.o: $(SRC_DIR)/$(STRING_DIR)/%.c | $(OBJ_DIR)/$(STRING_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

$(OBJ_DIR)/$(VECTOR_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(VECTOR_DIR)/%.o: $(SRC_DIR)/$(VECTOR_DIR)/%.c | $(OBJ_DIR)/$(VECTOR_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

# **************************************************************************** #

-include $(DEP)

# **************************************************************************** #

clean:
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	rm -f $(NAME)
	@printf "$(RESET)"

re: fclean all
