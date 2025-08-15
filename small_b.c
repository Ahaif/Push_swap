
#include "push_swap.h"

/* swap positions 2 and 3 locally without changing global head */
static void	swap_23_b(t_stack *b)
{
	rot(&b->head, &b->end);      /* rb */
	write(1, "rb\n", 3);
	swap(&b->head);              /* sb */
	write(1, "sb\n", 3);
	rrot(&b->head, &b->end);     /* rrb */
	write(1, "rrb\n", 4);
}

/* Make top3 on B strictly DESC using only sb and (rb;sb;rrb) */
static void	sort3_b_local(t_stack *b)
{
	if (b->head->n < b->head->next->n)
	{
		swap(&b->head);
		write(1, "sb\n", 3);
	}
	if (b->head->next->n < b->head->next->next->n)
		swap_23_b(b);
	if (b->head->n < b->head->next->n)
	{
		swap(&b->head);
		write(1, "sb\n", 3);
	}
}

void	sort_b(t_stack *b, int len)
{
	if (len == -1)
		len = 3;
	if (len <= 1)
		return ;
	if (len == 2)
	{
		/* B wants DESC */
		if (b->head->n < b->head->next->n)
		{
			swap(&b->head);
			write(1, "sb\n", 3);
		}
		return ;
	}
	/* len == 3 */
	sort3_b_local(b);
}
