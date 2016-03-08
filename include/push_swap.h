#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STACK_INC_FACTOR	8

# define F_VERBOSE			1
# define F_COLOR			2
# define F_GAME				4

typedef struct	s_stack
{
	int	len;
	int	size;
	int	*data;
}				t_stack;

#endif
