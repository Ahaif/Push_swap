/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:37:29 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/08 16:16:18 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head(t_stack *a, char **av)
{
	a->head = malloc(sizeof(t_nlst));
	if (!a->head)
		error_exit();
	else
	{
		a->head->n = ft_atoi(av[1]);
		a->head->prv = NULL;
		a->end = a->head;
	}
}

void	add_partition(t_stack *a, t_stack *b)
{
	a->p = malloc(sizeof(t_nlst *) * a->ac);
	if (!a->p)
		exit(1);
	b->p = malloc(sizeof(t_nlst *) * a->ac);
	if (!b->p)
		exit(1);
}

void	free_all(t_stack *a)
{
	t_nlst	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	free(a->p);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	build_stack(&a, ac, av);
	b.head = NULL;
	b.end = NULL;
	a.ac = ac;
	b.ac = ac;
	add_partition (&a, &b);
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	solver(&a, &b);
	free (b.p);
	free_all(&a);
}
