CC         =	gcc
CFLAGS     =	-Wall -Wextra -Werror
NAME       =	push_swap
SRCS       =	main.c stack.c operations.c errors.c print.c
ALGORITHMS =	stack_spill.c #full_rotate.c

# -----------------------------

vpath libft.a libft

help:
	@echo "+------------+"
	@echo "| all        |"
	@echo "| clean      |"
	@echo "| fclean     |"
	@echo "| re         |"
	@echo "| renolibft  |"
	@echo "+------------+"

all: libft.a $(NAME)

libft.a:
	make -C libft re;\

$(NAME):
	cd srcs;\
	$(CC) $(CFLAGS) -o ../$(NAME) -I ../include -I ../libft/includes $(SRCS) $(addprefix algorithms/,$(ALGORITHMS)) ../libft/libft.a

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean;\
	rm -f $(NAME)

re: fclean all

renolibft:
	rm -f $(NAME);\
	make $(NAME)

.PHONY: help all clean fclean re
