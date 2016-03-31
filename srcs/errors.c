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

int			print_error(char *error, char *explanation)
{
	static int	level;
	static char	flags;

	if (error == INIT_ERRORS)
	{
		flags = (char)explanation;
		return (0);
	}
	if (flags & F_ERRORS)
	{
		if (level == 0)
		{
			ft_printf("{{red;b}}WE GOT AN ERROR CAPT'N!!!{{eoc;}}");
			ft_printf("\nStack trace:\n");
		}
		ft_printf("[%d] -> {{yellow}}%s failed{{eoc}} (%s)\n",
			level++, error, explanation);
	}
	else if (level++ == 0)
		ft_printf("#!fd=2^Error\n");
	return (1);
}

static void	stack_minmax(t_stack *s)
{
	int	i;

	s->min = INT_MAX;
	s->max = INT_MIN;
	i = s->len;
	if (i < 1)
		return ;
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
		return (print_error(ERR_POSTCHECKFAIL, "Malloc failed"));
	ft_bzero(hits + i, sizeof(int) * i);
	ft_memcpy(hits, c->a.data, sizeof(int) * i);
	while (i--)
	{
		s = ft_arrayfind(hits, sizeof(int), c->a.len, c->a.data[i]);
		if (hits[s + c->a.len]++ > 0)
			return (print_error(ERR_POSTCHECKFAIL, "Duplicate number"));
	}
	stack_minmax(&c->a);
	stack_minmax(&c->b);
	return (0);
}
