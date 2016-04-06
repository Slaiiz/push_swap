/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:05:54 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/20 12:06:05 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_stacks(t_couple *c, int *argc, char ***argv)
{
	int		n;
	char	*s;

	*argv += *argc - 1;
	while (*argc)
	{
		s = *(*argv)--;
		if (ft_parseint(s, &n))
			return (print_error(ERR_INITFAIL, "integer overflow"));
		s += *s == '-';
		while (ft_isdigit(*s))
			s++;
		if (*s != '\0')
			return (print_error(ERR_INITFAIL, "Syntax error"));
		if (stack_push(&c->a, n))
			return (print_error(ERR_INITFAIL, "Undefined"));
		--*argc;
	}
	initialize_operations(c);
	return (perform_post_checks(c));
}

static void	initiate_user_interaction(t_couple *model, t_couple *c)
{
	char	*s;

	ft_printf("Here are your stacks:\n");
	print_snapshot(c);
	while (1)
	{
		ft_printf("Now whaddya' do? (sa sb ss pa pb ra rb rr rra rrb rrr)\n> ");
		if (get_next_line(0, &s) > 0
			&& ((!ft_strcmp(s, "sa") && !SA) || (!ft_strcmp(s, "sb") && !SB)
			|| (!ft_strcmp(s, "ss") && !SS) || (!ft_strcmp(s, "pa") && !PA)
			|| (!ft_strcmp(s, "pb") && !PB) || (!ft_strcmp(s, "ra") && !RA)
			|| (!ft_strcmp(s, "rb") && !RB) || (!ft_strcmp(s, "rr") && !RR)
			|| (!ft_strcmp(s, "rra") && !RRA) || (!ft_strcmp(s, "rrb") && !RRB)
			|| (!ft_strcmp(s, "rrr") && !RRR)))
		{
			free(s);
			if (c->len > model->len)
				ft_printf("YOU'VE LOST, SIR! Have a look at my solution:\n");
			else if (stack_is_ordered(&c->a) && !c->b.len)
				ft_printf("The victory is yours, well played. My solution:\n");
			else
				continue ;
			break ;
		}
	}
}

static int	sort_stacks(t_couple *c)
{
	int			len;
	t_couple	game;

	if (c->flags & F_GAME)
		c->flags &= ~F_VERBOSE;
	ft_memcpy(&game, c, sizeof(*c));
	len = c->a.len;
	if ((game.a.data = ft_memdup(c->a.data, 4 * len)) == NULL
		|| (len <= 6 && algorithm_full_rotate(c))
		|| (len > 6 && algorithm_stack_spill(c)))
		return (print_error(ERR_SORTFAIL, "Undefined"));
	if (c->flags & F_GAME)
	{
		game.flags = c->flags | F_VERBOSE | F_STATS | F_ERRORS | F_COLOR;
		ft_printf("#!clear^[{{red;b}}Game mode ENABLED{{eoc;}}]\n");
		initiate_user_interaction(c, &game);
	}
	free(game.a.data);
	return (0);
}

static int	parse_flags(int *argc, char ***argv, size_t *in)
{
	char	*args;

	while (*argc && --*argc && **(++*argv) == '-')
	{
		args = **argv;
		while (*++args != '\0')
		{
			if (*args == 'v')
				*in |= F_VERBOSE;
			else if (*args == 'c')
				*in |= F_COLOR;
			else if (*args == 'g')
				*in |= F_GAME | F_VERBOSE | F_STATS | F_ERRORS | F_COLOR;
			else if (*args == 'e')
				*in |= F_ERRORS;
			else if (*args == 's')
				*in |= F_STATS;
			else if (ft_isdigit(*args))
				return (0);
			else
			{
				print_error(INIT_ERRORS, (char*)F_ERRORS);
				return (print_error(ERR_PARSEFAIL, "Illegal flag"));
			}
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_couple	c;

	ft_bzero(&c, sizeof(c));
	if (parse_flags(&argc, &argv, &c.flags))
		return (print_error(ERR_MAINFAIL, "Undefined"));
	print_error(INIT_ERRORS, (char*)c.flags);
	if (argc < 1)
		return (print_error(ERR_MAINFAIL, "Missing argument(s)"));
	if (initialize_stacks(&c, &argc, &argv) || sort_stacks(&c))
		return (print_error(ERR_MAINFAIL, "Undefined"));
	print_operations(&c);
	return (0);
}
