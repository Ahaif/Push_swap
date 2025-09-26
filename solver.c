/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:18:16 by abhaifou          #+#    #+#             */
/*   Updated: 2025/09/04 10:18:19 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_a_to_b(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = get_count(a);
	median = NO_MED;
	if (count > 6)
		median = get_true_median(a);
	else if (count > 2 && count <= 6)
		median = get_special_median(a);
	if (median == FLAG)
		exit_error_all(a, b, NULL, NULL);
	if (median != NO_MED)
		split_arround_med(a, b, (int)median);
	else
		sort_a(a, count);
	if (median == NO_MED)
	{
		a->p[++(a->top)] = a->head;
		return (1);
	}
	return (0);
}

int	sorted(t_stack *a)
{
	t_nlst	*tmp;

	tmp = a->head;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_b(t_stack *b, t_stack *a, int count)
{
	int	i;

	i = 0;
	if (count == -1)
		count = 3;
	while (i < count)
	{
		push(&b->head, &a->head, &a->end);
		write(1, "pa\n", 3);
		i++;
	}
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = get_count(b);
	median = NO_MED;
	if (count > 2 && count <= 6)
		median = get_special_median_b(b);
	if (count > 6)
		median = get_true_median(b);
	if (median == FLAG)
		exit_error_all(a, b, NULL, NULL);
	if (median != NO_MED)
		split_from_med_b(a, b, (int)median);
	else
		sort_b(b, count);
	if (median == NO_MED)
		push_b(b, a, count);
}

void	solver(t_stack *a, t_stack *b)
{
	while (!sorted(a) || b->head)
	{
		if (!sorted(a))
		{
			while (split_a_to_b(a, b) == 0)
				;
		}
		else
			a->p[++(a->top)] = a->head;
		b_to_a(a, b);
	}
}
