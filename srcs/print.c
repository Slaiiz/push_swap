#include "push_swap.h"

void	print_snapshot(t_couple *c)
{
	int		i;
	t_stack	*s;

	ft_printf("Stack [{{red}}A{{eoc}}] = { {{cyan}}");
	s = &c->a;
	i = 0;
	while (i < s->len)
		ft_printf("%d ", s->data[i++]);
	ft_printf("{{eoc}}}\nStack [{{red}}B{{eoc}}] = { {{cyan}}");
	s = &c->b;
	i = 0;
	while (i < s->len)
		ft_printf("%d ", s->data[i++]);
	ft_printf("{{eoc}}}\n");
}

void	print_operations(t_couple *c)
{
	int	i;

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
	i = 0;
	while (i < c->len - 1)
		ft_printf("%s ", c->strings[c->ops[i++] - 1]);
	if (i > 0)
		ft_printf("%s\n", c->strings[c->ops[i] - 1]);
	if (c->flags & F_VERBOSE)
	{
		print_snapshot(c);
		ft_printf("{{yellow;b}}Total operations: {{eoc}}%lu\n", c->len);
	}
}
