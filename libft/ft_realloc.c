#include "libft.h"

void    *ft_realloc(void *ptr, size_t len)
{
	void    *real;

	if (!(real = malloc(len)))
		return (NULL);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy(real, ptr, len);
	free(ptr);
	return (real);
}
