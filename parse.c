

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atoi_long(const char *s, int *ok)
{
	long	sgn;
	long	x;
	int		i;

	*ok = 0;
	i = 0;
	sgn = 1;
	x = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sgn = -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
	{
		x = x * 10 + (s[i] - '0');
		if (x * sgn > INT_MAX || x * sgn < INT_MIN)
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*ok = 1;
	return (x * sgn);
}

static int	has_dup(t_nlst *h, int v)
{
	while (h)
	{
		if (h->n == v)
			return (1);
		h = h->next;
	}
	return (0);
}

static void	add_back(t_stack *a, int v)
{
	t_nlst	*n;

	n = (t_nlst *)malloc(sizeof(*n));
	if (!n)
		error_exit();
	n->n = v;
	n->next = NULL;
	n->prv = a->end;
	if (!a->head)
		a->head = n;
	if (a->end)
		a->end->next = n;
	a->end = n;
}

void	build_stack(t_stack *a, int ac, char **av)
{
	long	val;
	int		ok;
	int		i;

	i = 1;
	while (i < ac)
	{
		val = ft_atoi_long(av[i], &ok);
		if (!ok || has_dup(a->head, (int)val))
			error_exit();
		add_back(a, (int)val);
		i++;
	}
}