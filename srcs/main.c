#include "push_swap.h"

static int	initialize_stacks(t_stack *a, t_stack *b, char **argv[])
{
	int		n;
	char	*s;

	ft_bzero(a, sizeof(a));
	while (*(*argv)++)
	{
		s = **argv;
		n = ft_atoi(s);
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
			return (0);
		if (!stack_push(a, n))
			return (0);
	}
	ft_bzero(b, sizeof(b));
}

static void	parse_flags(int *in, char **argv[])
{
	char	*s;

	while (*++(*argv))
	{
		s = **argv;
		if (*s == '-')
		{
			s++;
			if (*s == 'v')
				in |= F_VERBOSE;
			else if (*s == 'c')
				in |= F_COLOR;
			else if (*s == 'g')
				in |= F_GAME;
			continue ;
		}
		break ;
	}
}

int			main(int argc, char *argv[])
{
	int		flags;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
	{
		ft_printf("#!fd=2^Error\n");
		return (1);
	}
	parse_flags(&flags, &argv);
	if (!initialize_stacks(&a, &b, &argv))
	{
		ft_printf("#!fd=2^Error\n");
		return (2);
	}
	if (!sort_stacks(&a, &b, flags))
	{
		ft_printf("#!fd=2^Error\n");
		return (4);
	}
}
