#include "push_swap.h"

static int	initialize_stacks(t_couple *c, char **argv[])
{
	int		n;
	char	*s;

	ft_bzero(c, sizeof(*c));
	while (*(*argv)++)
	{
		s = **argv;
		n = ft_atoi(s);
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
			return (0);
		if (!stack_push(&c->a, n))
			return (0);
	}
}

static int	sort_stacks(t_couple *c, int flags)
{
	if (!__push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB))
		return (0);
	return (1);
}

static int	print_stacks(t_couple *c, int flags)
{
	static char	*strings[11];

	strings[0]  = "SA";
	strings[1]  = "SB";
	strings[2]  = "SS";
	strings[3]  = "PA";
	strings[4]  = "PB";
	strings[5]  = "RA";
	strings[6]  = "RB";
	strings[7]  = "RR";
	strings[8]  = "RRA";
	strings[9]  = "RRB";
	strings[10] = "RRR";
	return (1);
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
	t_couple	c;
	int			flags;

	if (argc < 2)
	{
		ft_printf("#!fd=2^Error\n");
		return (1);
	}
	parse_flags(&flags, &argv);
	if (!initialize_stacks(&c, &argv))
	{
		ft_printf("#!fd=2^Error\n");
		return (2);
	}
	if (!sort_stacks(&c, flags))
	{
		ft_printf("#!fd=2^Error\n");
		return (4);
	}
	print_stacks(&c, flags);
}
