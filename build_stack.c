/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:20:34 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/08 15:33:25 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	error_exit(void)
{
	write (2, "Error\n", 7);
	exit(1);
}

int	check_only_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		if (!ft_isdigit(av[i][j]))
			return (0);
		while (ft_isdigit(av[i][j]))
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	add_node(char *str, t_nlst **end)
{
	t_nlst	*tmp;
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN || num == NO_MED)
		return (0);
	if (*end == NULL)
		return 0 ;
	tmp = malloc(sizeof(t_nlst));
	if(!tmp)
		return (0);
	tmp->n = (int)num;
	tmp->next = NULL;
	(*end)->next = tmp;
	tmp->prv = *end;
	*end = tmp;
	return (1);
}

int	check_double(t_stack *a)
{
	t_nlst	*tmp1;
	t_nlst	*tmp2;
	int		num;

	tmp1 = a->head;
	while (tmp1)
	{
		num = tmp1->n;
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (num == tmp2->next->n)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int build_stack(t_stack *a, int ac, char **av)
{
    t_nlst *tmp;

    if (!check_only_numbers(ac, av))
        return 0;


    if (!add_head(a, av))      // make add_head return 0 on malloc fail
        return 0;

    for (int i = 2; i < ac; i++) {
        if (!add_node(av[i], &a->end)) // make add_node return 0 on malloc/parse fail
            return 0;
    }

	if (!check_double(a)) {
        while (a->head) { tmp = a->head; a->head = a->head->next; free(tmp); }
        return 0;
    }

    return 1;
}
