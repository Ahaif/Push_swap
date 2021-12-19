/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:27:15 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/07 16:12:34 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_special_median_b(t_stack *b)
{
	t_nlst		*tmp;	
	int			i;
	int			arr[7];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_int_tab(arr, i);
	if (b->p[b->top])
		return (arr[2]);
	return (arr[3]);
}

int	deal_lower_nb_b(t_stack *b, int med, int *rewind)
{
	t_nlst	*tmp;
	int		i;

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top] && tmp->n <= med)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp == b->p[b->top])
		return (0);
	*rewind += i;
	while (i > 0)
	{
		ft_rotate(&b->head, &b->end);
		write(1, "rb\n", 3);
		i--;
	}
	return (1);
}

void	split_from_med_b(t_stack *a, t_stack *b, int med)
{
	int	rewind;

	rewind = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->n > med)
		{
			push(&b->head, &a->head, &a->end);
			write(1, "pa\n", 3);
		}
		else if (deal_lower_nb_b(b, med, &rewind) == 0)
			break ;
	}
	while (b->p[b->top] && rewind > 0)
	{
		ft_reverse_rotate(&b->head, &b->end);
		write (1, "rrb\n", 4);
		rewind --;
	}
}

void	three_case_nb_b(t_stack *b)
{
	while (!(b->head->next->n > b->head->next->next->n
			&& b->head->n > b->head->next->next->n))
	{
		if (b->head->next->n < b->head->next->next->n
			&& b->head->next->n < b->head->n)
		{
			ft_reverse_rotate(&b->head, &b->end);
			write(1, "rrb\n", 4);
		}
		else
		{
			ft_rotate(&b->head, &b->end);
			write(1, "rb\n", 3);
		}
	}
	if (!(b->head->n > b->head->next->n))
		return ;
	swap(&b->head);
	write(1, "sb\n", 3);
}

void	sort_b(t_stack *b, int count)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->n > b->head->n)
		{
			swap(&b->head);
			write (1, "sb\n", 3);
		}
		return ;
	}
	three_case_nb_b(b);
}
