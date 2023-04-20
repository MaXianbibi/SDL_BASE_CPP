NAME = BSDL
CC = g++ -std=c++20
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lSDL2
RM = rm -f

SRC_DIR = src/
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ_DIR = objs/
OBJS = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@ || ( $(MAKE) kill_spinner ; exit 1 )

all: 		$(NAME)

$(NAME): 	spinner $(OBJS)
			@$(CC) $(OBJS) $(LDFLAGS) -o $@ || ( $(MAKE) kill_spinner ; exit 1 )
			@$(MAKE) kill_spinner
			@echo "\r\033[33mDONE!\033[0m         "

clean:
			@$(RM) -r $(OBJ_DIR)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

spinner:
			@chmod +x spinner.sh
			@./spinner.sh &

kill_spinner:
			@pgrep -f spinner.sh > /dev/null 2>&1 && pkill -f spinner.sh || true

.PHONY: 	all clean fclean re
