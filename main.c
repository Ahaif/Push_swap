/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:18:04 by abhaifou          #+#    #+#             */
/*   Updated: 2025/09/04 10:18:07 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_all(t_stack *a, t_stack *b, char **split, char **argv_fake)
{
	if (a)
		free_stack_shallow(a);
	if (b)
		free_stack_shallow(b);
	if (argv_fake)
		free(argv_fake);
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	add_partition(t_stack *a, t_stack *b)
{
	a->p = (t_nlst **)malloc(sizeof(t_nlst *) * a->ac);
	if (!a->p)
		return (0);
	b->p = (t_nlst **)malloc(sizeof(t_nlst *) * a->ac);
	if (!b->p)
	{
		free(a->p);
		a->p = NULL;
		return (0);
	}
	return (1);
}

int	add_head(t_stack *a, char **av)
{
	long	val;

	a->head = (t_nlst *)malloc(sizeof(t_nlst));
	if (!a->head)
		return (0);
	a->head->next = NULL;
	a->head->prv = NULL;
	val = ft_atoi(av[1]);
	if (val == NO_MED)
		return (0);
	a->head->n = (int)val;
	a->end = a->head;
	return (1);
}

static int	run_push_swap(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**split;
	char	**argv_fake;

	a = (t_stack){0};
	b = (t_stack){0};
	split = NULL;
	argv_fake = NULL;
	if (!prepare_argv(&ac, &av, &split, &argv_fake))
		return (0);
	if (!build_stack(&a, ac, av))
		exit_error_all(&a, &b, split, argv_fake);
	a.ac = ac;
	b.ac = ac;
	if (!add_partition(&a, &b))
		exit_error_all(&a, &b, split, argv_fake);
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[b.top] = NULL;
	solver(&a, &b);
	cleanup_and_free(&a, &b, split, argv_fake);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!run_push_swap(ac, av))
		return (0);
	return (0);
}
