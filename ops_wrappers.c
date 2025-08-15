#include "push_swap.h"
#include <unistd.h>

/* swaps */
void op_sa(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		swap(&a->head);
		write(1, "sa\n", 3);
	}
}

void op_sb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		swap(&b->head);
		write(1, "sb\n", 3);
	}
}

void op_ss(t_stack *a, t_stack *b)
{
	int did = 0;

	if (a && a->head && a->head->next) { swap(&a->head); did = 1; }
	if (b && b->head && b->head->next) { swap(&b->head); did = 1; }
	if (did)
		write(1, "ss\n", 3);
}

/* pushes */
void op_pa(t_stack *a, t_stack *b) /* b -> a */
{
	if (a && b && b->head)
	{
		push(&b->head, &a->head, &a->end);
		write(1, "pa\n", 3);
	}
}

void op_pb(t_stack *a, t_stack *b) /* a -> b */
{
	if (a && b && a->head)
	{
		push(&a->head, &b->head, &b->end);
		write(1, "pb\n", 3);
	}
}

/* rotates */
void op_ra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		ft_rotate(&a->head, &a->end);
		write(1, "ra\n", 3);
	}
}

void op_rb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		ft_rotate(&b->head, &b->end);
		write(1, "rb\n", 3);
	}
}

void op_rr(t_stack *a, t_stack *b)
{
	int did = 0;

	if (a && a->head && a->head->next) { ft_rotate(&a->head, &a->end); did = 1; }
	if (b && b->head && b->head->next) { ft_rotate(&b->head, &b->end); did = 1; }
	if (did)
		write(1, "rr\n", 3);
}

/* reverse rotates */
void op_rra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		ft_reverse_rotate(&a->head, &a->end);
		write(1, "rra\n", 4);
	}
}

void op_rrb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		ft_reverse_rotate(&b->head, &b->end);
		write(1, "rrb\n", 4);
	}
}

void op_rrr(t_stack *a, t_stack *b)
{
	int did = 0;

	if (a && a->head && a->head->next) { ft_reverse_rotate(&a->head, &a->end); did = 1; }
	if (b && b->head && b->head->next) { ft_reverse_rotate(&b->head, &b->end); did = 1; }
	if (did)
		write(1, "rrr\n", 4);
}
