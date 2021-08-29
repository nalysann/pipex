NAME := pipex

# **************************************************************************** #

SRC_DIR := src

SRC := pipex.c \
       utils.c

OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)

SRC_BONUS := pipex_bonus.c \
             utils.c

OBJ_BONUS := $(SRC_BONUS:.c=.o)
DEP_BONUS := $(SRC_BONUS:.c=.d)

# **************************************************************************** #

FT_DIR := libft
FT := libft.a

# **************************************************************************** #

INC_DIRS := include \
            $(FT_DIR)/include \

# **************************************************************************** #

OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))
DEP := $(addprefix $(OBJ_DIR)/, $(DEP))

NAME_BONUS := $(addprefix $(OBJ_DIR)/, $(NAME))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/, $(OBJ_BONUS))
DEP_BONUS := $(addprefix $(OBJ_DIR)/, $(DEP_BONUS))

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

LDFLAGS += -L $(FT_DIR)

LDLIBS += -lft

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

.PHONY: all bonus clean fclean re

# **************************************************************************** #

all:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR)
	@printf "$(CYAN)>>> Making $(NAME) <<<\n$(RESET)"
	@$(MAKE) $(NAME)

bonus:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR)
	@printf "$(CYAN)>>> Making $(NAME) <<<\n$(RESET)"
	@$(MAKE) $(NAME_BONUS)
	@cp $(NAME_BONUS) $(NAME)

$(FT_DIR)/$(FT):
	@$(MAKE) -C $(FT_DIR)

$(NAME): $(OBJ) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@printf "$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ_BONUS) -o $@
	@printf "$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

-include $(DEP)
-include $(DEP_BONUS)

clean:
	@printf "$(CYAN)>>> Cleaning $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(CYAN)>>> Purging $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) fclean
	@printf "$(CYAN)>>> Purging $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -f $(NAME)
	@printf "$(RESET)"

re: fclean all
