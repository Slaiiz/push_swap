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

	*argv += *argc - 2;
	while (*argc > 1)
	{
		s = *(*argv)--;
		n = ft_atoi(s);
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
		{
			print_error(ERR_INITFAIL, DET_SYNTAX);
			return (1);
		}
		if (stack_push(&c->a, n))
		{
			print_error(ERR_INITFAIL, DET_UNDEFINED);
			return (1);
		}
		--*argc;
	}
	return (0);
}

static int	sort_stacks(t_couple *c)
{
	if (__swap(c, A)
		|| __push(c, B)
		|| __push(c, B)
		|| __push(c, B)
		|| __rotate(c, A)
		|| __rotate(c, B)
		|| __reverse_rotate(c, A)
		|| __reverse_rotate(c, B)
		|| __swap(c, A)
		|| __push(c, A)
		|| __push(c, A)
		|| __push(c, A))
		return (1);
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
		print_error(ERR_MAIN, DET_INVARG);
		return (1);
	}
	if (initialize_stacks(&c, &argc, &argv))
	{
		print_error(ERR_MAIN, DET_UNDEFINED);
		return (1);
	}
	if (sort_stacks(&c))
	{
		print_error(ERR_MAIN, DET_UNDEFINED);
		return (1);
	}
	print_operations(&c);
	return (0);
}
