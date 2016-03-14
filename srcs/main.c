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
	initialize_operations(c);
	// return(perform_post_checks(c));
	return (0);
}

static int	sort_stacks(t_couple *c)
{
	int	error;
	int	sorting;

	sorting = 1;
	while (sorting)
	{
		if (!c->a.len)
		{
			while (c->b.data[0] != c->b.min)
				RRB;
			while (c->b.len)
				if (PA)
				{
					sorting = 0;
					break ;
				}
			if (sorting)
				return (0);
		}
		else if ((error = check_need_for_swap(c)) == -1)
			break ;
		else if (!error)
			if (force_insertion_into_b(c))
				break ;
	}
	print_error(ERR_SORTFAIL, DET_UNDEFINED);
	return (1);
}

static int	parse_flags(char *in, int *argc, char ***argv)
{
	char	*s;

	while (*argc > 1 && (s = *(++*argv)) && s[0] == '-')
	{
		if (s[1] == 'v')
			*in |= F_VERBOSE;
		else if (s[1] == 'c')
			*in |= F_COLOR;
		else if (s[1] == 'g')
			*in |= F_GAME;
		else if (s[1] == 'e')
			*in |= F_ERRORS;
		else if (ft_isdigit(s[1]))
			return (0);
		else if (*in & F_ERRORS)
		{
			print_error(INIT_ERRORS, F_ERRORS);
			print_error(ERR_PARSE, DET_BADFLAG);
			return (1);
		}
		--*argc;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_couple	c;

	ft_bzero(&c, sizeof(c));
	if (parse_flags(&c.flags, &argc, &argv))
	{
		print_error(ERR_MAIN, DET_UNDEFINED);
		return (1);
	}
	print_error(INIT_ERRORS, c.flags);
	if (argc < 2)
	{
		print_error(ERR_MAIN, DET_INVARG);
		return (1);
	}
	if (initialize_stacks(&c, &argc, &argv) || sort_stacks(&c))
	{
		print_error(ERR_MAIN, DET_UNDEFINED);
		return (1);
	}
	print_operations(&c);
	return (0);
}
