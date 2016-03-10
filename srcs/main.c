/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:34:54 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/10 16:34:56 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_stacks(t_couple *c, int *argc, char ***argv)
{
	int		n;
	char	*s;

	ft_bzero(c, sizeof(*c));
	while (*argc)
	{
		s = *(*argv)++;
		n = ft_atoi(s);
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
			return (ERR_BADARG);
		if (!stack_push(&c->a, n))
			return (ERR_PUSHFAIL);
		--*argc;
	}
	c->strings[0]  = "SA";
	c->strings[1]  = "SB";
	c->strings[2]  = "SS";
	c->strings[3]  = "PA";
	c->strings[4]  = "PB";
	c->strings[5]  = "RA";
	c->strings[6]  = "RB";
	c->strings[7]  = "RR";
	c->strings[8]  = "RRA";
	c->strings[9]  = "RRB";
	c->strings[10] = "RRR";
	return (0);
}

static int	sort_stacks(t_couple *c, int flags)
{
	if (!__push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB))
		return (1);
	return (0);
}

static int	print_stacks(t_couple *c, int flags)
{
	int	i;

	i = 0;
	while (i < c->len - 1)
		ft_printf("%s ", c->strings[c->ops[i++] - 1]);
	if (i > 0)
		ft_printf("%s\n", c->strings[c->ops[i] - 1]);
	return (0);
}

static void	parse_flags(int *in, int *argc, char ***argv)
{
	char	*s;

	while (*argc > 1)
	{
		--*argc;
		s = *(++*argv);
		if (*s == '-')
		{
			s++;
			if (*s == 'v')
				*in |= F_VERBOSE;
			else if (*s == 'c')
				*in |= F_COLOR;
			else if (*s == 'g')
				*in |= F_GAME;
			else if (*s == 'e')
				*in |= F_ERRORS;
			continue ;
		}
		break ;
	}
}

int			main(int argc, char **argv)
{
	t_couple	c;
	int			flags;

	if (argc < 2)
	{
		ft_printf("#!fd=2^Error\n");
		print_error(ERR_INVARGS);
		return (1);
	}
	parse_flags(&flags, &argc, &argv);
	if (initialize_stacks(&c, &argc, &argv))
	{
		ft_printf("#!fd=2^Error\n");
		print_error(ERR_INITFAIL);
		return (1);
	}
	if (sort_stacks(&c, flags))
	{
		ft_printf("#!fd=2^Error\n");
		print_error(ERR_SORTFAIL);
		return (1);
	}
	print_stacks(&c, flags);
	return (0);
}
