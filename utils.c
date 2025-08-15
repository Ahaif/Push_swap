

#include "push_swap.h"

int	list_size(t_nlst *h)
{
	int	n;

	n = 0;
	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}

