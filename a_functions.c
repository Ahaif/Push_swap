/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:16:23 by abhaifou          #+#    #+#             */
/*   Updated: 2025/09/04 10:16:29 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nb_case(t_stack *a)
{
	while (!(a->head->next->n < a->head->next->next->n
			&& a->head->n < a->head->next->next->n))
	{
		if (a->head->next->n > a->head->next->next->n
			&& a->head->next->n > a->head->n)
		{
			ft_reverse_rotate(&a->head, &a->end);
			write(1, "rra\n", 4);
		}
		else
		{
			ft_rotate(&a->head, &a->end);
			write (1, "ra\n", 3);
		}
	}
	if (a->head->n < a->head->next->n)
		return ;
	swap(&a->head);
	write(1, "sa\n", 3);
}

void	sort_a(t_stack *a, int count)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->n > a->head->next->n)
		{
			swap(&a->head);
			write(1, "sa\n", 3);
		}
		return ;
	}
	else
		three_nb_case(a);
}

int	deal_higher_nb_a(t_stack *a, int median, int *rewind)
{
	t_nlst	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top] && tmp->n > median)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp == a->p[a->top])
		return (0);
	*rewind += i;
	while (i > 0)
	{
		ft_rotate(&a->head, &a->end);
		write(1, "ra\n", 3);
		i--;
	}
	return (1);
}

void	split_arround_med(t_stack *a, t_stack *b, int median)
{
	int	rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->n <= median)
		{
			push (&a->head, &b->head, &b->end);
			write(1, "pb\n", 3);
		}
		else if (deal_higher_nb_a(a, median, &rewind) == 0)
			break ;
	}
	while (a->p[a->top] && rewind > 0)
	{
		ft_reverse_rotate(&a->head, &a->end);
		write (1, "rra\n", 4);
		rewind--;
	}
}
