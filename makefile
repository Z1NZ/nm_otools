#	Library output
NAME = ft_nm

#	GCC flags
ALL_CFLAGS = -Wall -Wextra -Werror -Weverything

#	Includes directories
INC = includes
INCLUDES += $(addprefix -iquote , $(INC))

#	Sources
PUSH_SWAP_SOURCES = $(shell find lib | grep "\.c$$" | sed "s/\.c$$//g")
SRCS = $(addsuffix .c, $(PUSH_SWAP_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de ($(NAME))"
	gcc $(ALL_CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) -g
	@echo "Terminée"

# To obtain object files
%.o: %.c
	$(CC) -c $(ALL_CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

lftclean:
	make -C libft clean

lftfclean:
	make -C libft fclean

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push