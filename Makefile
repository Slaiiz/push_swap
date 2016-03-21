CC         =	gcc
CFLAGS     =	-Wall -Wextra -Werror
NAME       =	push_swap
SRCS       =	main.c stack.c operations.c errors.c print.c ../get_next_line/get_next_line.c
ALGORITHMS =	full_rotate.c stack_spill.c
INCLUDE    =	include libft/include get_next_line

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
	$(CC) $(CFLAGS) -o ../$(NAME) $(addprefix -I ../,$(INCLUDE)) $(SRCS) $(addprefix algorithms/,$(ALGORITHMS)) ../libft/libft.a

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
