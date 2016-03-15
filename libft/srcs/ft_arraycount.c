#include "libft.h"

int	ft_arraycount(void *a, int bytesize, int len, size_t n)
{
	int	i;
	int	hits;

	hits = 0;
	while (1)
	{
		if ((i = ft_arrayfind(a, bytesize, len, n)) != -1)
			hits++;
		else
			break ;
		a += bytesize * (i + 1);
		len -=  i + 1;
	}
	return (hits);
}
