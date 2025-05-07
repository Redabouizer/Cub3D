NAME = cube3d

CC = cc

CFLAGS = #-Wall -Wextra -Werror

READLINE_LIB = $(shell brew --prefix readline)/lib
READLINE_INC = $(shell brew --prefix readline)/include

LDFLAGS = -L $(READLINE_LIB) -lreadline
INC_DIR = ./includes
INCLUDES = -I $(READLINE_INC) -I $(INC_DIR)

SRCS = \
    

HEADER = 
OBJ_DIR = objectFile
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o)) #how it is work

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

	#for what this
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)          # Create the necessary subdirectories in obj/
	@echo "🔨 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️  Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
