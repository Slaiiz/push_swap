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

	while (*argc > 1)
	{
		s = *(*argv)++;
		n = ft_atoi(s);
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
		{
			print_error(ERR_BADARG, 0);
			return (1);
		}
		if (stack_push(&c->a, n))
		{
			print_error(ERR_PUSHFAIL, 0);
			return (1);
		}
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

static int	sort_stacks(t_couple *c)
{
	if (__push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PB)
		|| __push(c, O_PA))
		return (1);
	return (0);
}

static int	print_stacks(t_couple *c)
{
	int	i;

	i = 0;
	while (i < c->len - 1)
		ft_printf("%s ", c->strings[c->ops[i++] - 1]);
	if (i > 0)
		ft_printf("%s\n", c->strings[c->ops[i] - 1]);
	return (0);
}

static void	parse_flags(char *in, int *argc, char ***argv)
{
	char	*s;

	while (*argc > 1)
	{
		s = *(++*argv);
		if (s[0] == '-')
		{
			if (s[1] == 'v')
				*in |= F_VERBOSE;
			else if (s[1] == 'c')
				*in |= F_COLOR;
			else if (s[1] == 'g')
				*in |= F_GAME;
			else if (s[1] == 'e')
				*in |= F_ERRORS;
			else
				break ;
			--*argc;
			continue ;
		}
		break ;
	}
}

int			main(int argc, char **argv)
{
	t_couple	c;

	ft_bzero(&c, sizeof(c));
	parse_flags(&c.flags, &argc, &argv);
	print_error(INIT_ERRORS, c.flags);
	if (argc < 2)
	{
		print_error(ERR_INVARGS, 0);
		return (1);
	}
	if (initialize_stacks(&c, &argc, &argv))
	{
		print_error(ERR_INITFAIL, 0);
		return (1);
	}
	if (sort_stacks(&c))
	{
		print_error(ERR_SORTFAIL, 0);
		return (1);
	}
	print_stacks(&c);
	return (0);
}
