### COMPILATION ###
CC      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = pipex

### INCLUDES ###
LIBFT  = libft
OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = srcs

### SOURCE FILES ###
SOURCES = pipex.c \
		  split.c \
### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
WHITE       = \033[1;37m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(YELLOW)-- LIBFT COMPILING --$(CYAN)"
	@make -C $(LIBFT)
	@echo "$(GREEN)--LIBFT COMPILED --"

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft
	@echo "$(GREEN)-- PIPEX COMPILED --"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)-- CLEAN DONE --$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)-- FCLEAN DONE --$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make clean -C $(LIBFT)
	@make clean
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean