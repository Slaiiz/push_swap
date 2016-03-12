#include "push_swap.h"

static void	init_errors(char **out)
{
	out[0]  = "Invalid/Missing argument(s)";
	out[1]  = "init_stacks() failed";
	out[2]  = "sort_stacks() failed";
	out[3]  = "malloc() failed";
	out[4]  = "push() failed";
	out[5]  = "rotate() failed";
	out[6]  = "reverse_rotate() failed";
	out[7]  = "Stack not large enough for action";
	out[8]  = "swap() failed";
	out[9]  = "Invalid argument syntax";
	out[10] = "No details";
	out[11] = "Could not register operation";
	out[12] = "Operation failed";
	out[13] = "main() failed";
}

void		print_error(int id, int arg)
{
	static int	level;
	static char	flags;
	static char	*errors[14];

	if (id == INIT_ERRORS)
	{
		init_errors(errors);
		flags = arg;
		return ;
	}
	if (flags & F_ERRORS)
	{
		if (level == 0)
		{
			ft_printf("{{red;b}}WE GOT AN ERROR CAPT'N!!!{{eoc;}}");
			ft_printf("\nStack trace:\n*");
		}
		ft_printf(" [%d] -> {{yellow}}%s{{eoc}} (%s)\n",
			level++, errors[id], errors[arg]);
	}
	else if (level++ == 0)
		ft_printf("#!fd=2^Error\n");
}
