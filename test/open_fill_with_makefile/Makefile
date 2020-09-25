

NAME = fillit
CC = gcc
FLAGS =  -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)
HEADERS_LIST = get_next_line.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST =	main.c \
								get_next_line.c
SOURCES_DIRECTORY = ./src/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

ARGS = sample.fillit
IMPORT_DIRECTORY = ./import/


# Compile and create everything.
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(NAME): Object files are created$(RESET)"
	@echo "$(NAME): $(NAME) is created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(OBJECTS_DIRECTORY) directory is created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(NAME): Creating $*.o$(RESET)"

$(LIBFT):
	@echo "$(NAME): Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

.PHONY: all clean fclean re

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(OBJECTS_DIRECTORY) directory is deleted$(RESET)"
	@echo "$(NAME): object files are deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(LIBFT) is deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(NAME) is deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

run: $(NAME)
	@clear
	@echo "./$(NAME) ${ARGS} $(RESET)"
	@echo "Running $(NAME)$(RESET)"
	-@./$(NAME) ${IMPORT_DIRECTORY}${ARGS}

