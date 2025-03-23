#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count && size && count > (4294967295 / size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}