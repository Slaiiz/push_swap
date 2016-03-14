#include "libft.h"

int	ft_arrayfind(void *a, int bytesize, int len, size_t n)
{
	size_t	mask;

	mask = (1 << (8 * bytesize - 1)) - 1;
	mask |= (mask + 1);
	while (len--)
	{
		if (!(((size_t*)*a ^ n) & mask))
			return (len);
		(char*)*a += bytesize;
	}
	return (-1);
}
