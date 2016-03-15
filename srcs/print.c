/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:34:58 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/12 16:34:59 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_averages(t_couple *c)
{
	ft_printf("{{yellow;b}}Average operation usage:\n");
	ft_printf("{{eoc;}}sa/sb/ss:    {{green;b}}%3d%%\n",
		(ft_arraycount(c->ops, 1, c->len, O_SA)
		+ ft_arraycount(c->ops, 2, c->len, O_SB)
		+ ft_arraycount(c->ops, 4, c->len, O_SS)) * 100 / c->len);
	ft_printf("{{eoc;}}pa/pb:       {{green;b}}%3d%%\n",
		(ft_arraycount(c->ops, 1, c->len, O_PA)
		+ ft_arraycount(c->ops, 1, c->len, O_PB)) * 100 / c->len);
	ft_printf("{{eoc;}}ra/rb/rr:    {{green;b}}%3d%%\n",
		(ft_arraycount(c->ops, 1, c->len, O_RA)
		+ ft_arraycount(c->ops, 1, c->len, O_RB)
		+ ft_arraycount(c->ops, 1, c->len, O_RR)) * 100 / c->len);
	ft_printf("{{eoc;}}rra/rrb/rrr: {{green;b}}%3d%%\n{{eoc;}}",
		(ft_arraycount(c->ops, 1, c->len, O_RRA)
		+ ft_arraycount(c->ops, 1, c->len, O_RRB)
		+ ft_arraycount(c->ops, 1, c->len, O_RRR)) * 100 / c->len);
	ft_printf("%d\n", ft_arraycount(c->ops, 1, c->len, O_PB));
}

static void	print_change(t_couple *c, int o)
{
	if (c->flags & F_COLOR)
	{
		if (o == A)
		{
			if (c->ops[c->len - 1] == O_PB)
				ft_printf("{{red;b}}- ");
			else if (c->ops[c->len - 1] == O_PA)
				ft_printf("{{green;b}}+ ");
			return ;
		}
		if (c->ops[c->len - 1] == O_PB)
			ft_printf("{{green;b}}+ ");
		else if (c->ops[c->len - 1] == O_PA)
			ft_printf("{{red;b}}- ");
	}
}

void		initialize_operations(t_couple *c)
{
	c->strings[0]  = "sa";
	c->strings[1]  = "sb";
	c->strings[2]  = "ss";
	c->strings[3]  = "pa";
	c->strings[4]  = "pb";
	c->strings[5]  = "ra";
	c->strings[6]  = "rb";
	c->strings[7]  = "rr";
	c->strings[8]  = "rra";
	c->strings[9]  = "rrb";
	c->strings[10] = "rrr";
}

void		print_snapshot(t_couple *c)
{
	int		i;
	t_stack	*s;

	ft_printf("  Stack [{{red}}A{{eoc}}] = { {{cyan}}");
	s = &c->a;
	i = 0;
	while (i < s->len)
		ft_printf("%d ", s->data[i++]);
	print_change(c, A);
	ft_printf("{{eoc;}}}\n  Stack [{{red}}B{{eoc}}] = { {{cyan}}");
	s = &c->b;
	i = 0;
	while (i < s->len)
		ft_printf("%d ", s->data[i++]);
	print_change(c, B);
	ft_printf("{{eoc;}}}\n");
}

void		print_operations(t_couple *c)
{
	int	i;

	if (c->len > 0)
	{
		i = 0;
		while (i < c->len - 1)
			ft_printf("%s ", c->strings[c->ops[i++] - 1]);
		ft_printf("%s\n", c->strings[c->ops[i] - 1]);
	}
	if (c->flags & F_STATS)
		print_averages(c);
	if (c->flags & F_VERBOSE)
		ft_printf("{{yellow;b}}Total operations: {{eoc}}%lu\n", c->len);
}
