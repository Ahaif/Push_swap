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
	write (1, "error\n", 7);
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

void	add_node(char *str, t_nlst **end)
{
	t_nlst	*tmp;
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		error_exit();
	if (*end == NULL)
		return ;
	tmp = malloc(sizeof(t_nlst));
	tmp->n = (int)num;
	tmp->next = NULL;
	(*end)->next = tmp;
	tmp->prv = *end;
	*end = tmp;
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

void	build_stack(t_stack *a, int ac, char **av)
{
	int		i;
	t_nlst	*tmp;

	i = 1;
	if (!check_only_numbers(ac, av))
		error_exit();
	add_head(a, av);
	i++;
	while (i < ac)
		add_node(av[i++], &a->end);
	if (!check_double(a))
	{
		while (a->head)
		{
			tmp = a->head;
			a->head = a->head->next;
			free(tmp);
		}
		error_exit();
	}
}
/*int main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	if (ac > 1 )
	{
		build_stack(&a, &b, ac, av);
	
		//printf("%d", a.head->n);
		while(a.head)
		{
			
			printf("%d", a.head->n);
			a.head = a.head->next;
		}
	}
	return (0);
}*/
