/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:17:15 by abhaifou          #+#    #+#             */
/*   Updated: 2025/09/04 10:17:21 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack_nodes(t_nlst **head)
{
	t_nlst	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	free_all(t_stack *s)
{
	if (!s)
		return ;
	free_stack_nodes(&s->head);
	if (s->p)
	{
		free(s->p);
		s->p = NULL;
	}
	s->end = NULL;
	s->top = 0;
}

void	cleanup_and_free(t_stack *a, t_stack *b, char **split, char **argv_fake)
{
	free_all(a);
	free_all(b);
	if (argv_fake)
		free(argv_fake);
	if (split)
		free_split(split);
}

void	free_stack_shallow(t_stack *s)
{
	t_nlst	*tmp;

	if (!s)
		return ;
	while (s->head)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
	if (s->p)
	{
		free(s->p);
		s->p = NULL;
	}
}
