/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:34:48 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/20 12:05:47 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_errors(char **out)
{
	out[0] = "Invalid/Missing argument(s)";
	out[1] = "init_stacks()";
	out[2] = "sort_stacks()";
	out[3] = "malloc()";
	out[4] = "push()";
	out[5] = "rotate()";
	out[6] = "reverse_rotate()";
	out[7] = "Stack not large enough for action";
	out[8] = "swap()";
	out[9] = "Invalid argument syntax";
	out[10] = "No details";
	out[11] = "Could not register operation";
	out[12] = "Operation failed";
	out[13] = "main()";
	out[14] = "Unrecognized flag";
	out[15] = "parse_flags()";
	out[16] = "perform_post_checks()";
	out[17] = "Same number appearing more than once";
	out[18] = "check_swap()";
	out[19] = "check_rotation()";
	out[20] = "send_all_to_b()";
	out[21] = "retrieve_all_from_b()";
	out[22] = "algorithm_stack_spill()";
}

void		print_error(int id, int arg)
{
	static int	level;
	static char	flags;
	static char	*errors[23];

	if (id == INIT_ERRORS)
	{
		initialize_errors(errors);
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
		ft_printf(" [%d] -> {{yellow}}%s failed{{eoc}}", level++, errors[id]);
		if (arg != DET_UNDEFINED)
			ft_printf(" (%s)\n", errors[arg]);
	}
	else if (level++ == 0)
		ft_printf("#!fd=2^Error\n");
}

static void	stack_minmax(t_stack *s)
{
	int	i;

	i = s->len;
	if (i < 1)
	{
		s->min = INT_MAX;
		s->max = INT_MIN;
		return ;
	}
	s->min = INT_MAX;
	s->max = INT_MIN;
	while (i--)
	{
		if (s->data[i] < s->min)
			s->min = s->data[i];
		if (s->data[i] > s->max)
			s->max = s->data[i];
	}
}


int			perform_post_checks(t_couple *c)
{
	int	i;
	int	s;
	int	*hits;

	i = c->a.len;
	if ((hits = malloc(sizeof(int) * (2 * i))) == NULL)
	{
		print_error(ERR_POSTCHECKFAIL, DET_MALLOC);
		return (1);
	}
	ft_bzero(hits + i, sizeof(int) * i);
	ft_memcpy(hits, c->a.data, sizeof(int) * i);
	while (i--)
	{
		s = ft_arrayfind(hits, sizeof(int), c->a.len, c->a.data[i]);
		if (hits[s + c->a.len]++ > 0)
		{
			print_error(ERR_POSTCHECKFAIL, DET_DOUBLE);
			return (1);
		}
	}
	stack_minmax(&c->a);
	stack_minmax(&c->b);
	return (0);
}
