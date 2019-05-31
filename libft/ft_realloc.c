#include "libft.h"

void    *ft_realloc(void *ptr, size_t len, size_t first)
{
	void    *real;

	if (!(real = malloc(len)))
		return (NULL);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy_fillit(real, &ptr[first], len);
	free(ptr);
	return (real);
}
