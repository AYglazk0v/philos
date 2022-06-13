#include "../../inc/utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	k;

	k = (int)n;
	while (--k >= 0)
	{
		*((unsigned char *)(s + k)) = (char)c;
	}
	return (s);
}