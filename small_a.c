


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_a.c                                          :+:      :+:    :+:   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap positions 2 and 3 locally without changing global head */
static void	swap_23_a(t_stack *a)
{
	rot(&a->head, &a->end);      /* ra */
	write(1, "ra\n", 3);
	swap(&a->head);              /* sa */
	write(1, "sa\n", 3);
	rrot(&a->head, &a->end);     /* rra */
	write(1, "rra\n", 4);
}

/* Make top3 on A strictly ASC using only sa and (ra;sa;rra) */
static void	sort3_a_local(t_stack *a)
{
	if (a->head->n > a->head->next->n)
	{
		swap(&a->head);
		write(1, "sa\n", 3);
	}
	if (a->head->next->n > a->head->next->next->n)
		swap_23_a(a);
	if (a->head->n > a->head->next->n)
	{
		swap(&a->head);
		write(1, "sa\n", 3);
	}
}

void	sort_a(t_stack *a, int len)
{
	if (len == -1)
		len = 3;
	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (a->head->n > a->head->next->n)
		{
			swap(&a->head);
			write(1, "sa\n", 3);
		}
		return ;
	}
	/* len == 3 */
	sort3_a_local(a);
}
