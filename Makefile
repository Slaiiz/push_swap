CC     =	gcc
CFLAGS =	-Wall -Wextra -Werror
NAME   =	push_swap
SRCS   =	main.c

# -----------------------------

help:
	@echo "\033[33;41mAvailable rules:\033[0m\n\
	\033[30;43mhelp     \033[0m\n\
	\033[30;43mall      \033[0m\n\
	\033[30;43mclean    \033[0m\n\
	\033[30;43mfclean   \033[0m\n\
	\033[30;43mre       \033[0m\n\
	\033[30;43mrenolibft\033[0m\n"

all: libft.a $(NAME)

libft.a:
	make -C libft re;\
	mv libft/libft.a .

$(NAME):
	cd srcs;\
	$(CC) $(CFLAGS) -o ../$(NAME) -I include -I libft/include $(SRCS) libft.a

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

renolibft: fclean $(NAME)

.PHONY: help all clean fclean re
