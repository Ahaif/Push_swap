/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:17:54 by abhaifou          #+#    #+#             */
/*   Updated: 2025/09/04 10:17:57 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nlst **stack)
{
	t_nlst	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prv = *stack;
	(*stack)->next = tmp;
	(*stack)->prv = NULL;
}

void	push(t_nlst **from, t_nlst **to, t_nlst **to_end)
{
	t_nlst	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	(*from) = (*from)->next;
	if (*from)
		(*from)->prv = NULL;
	if (*to)
		(*to)->prv = tmp;
	else
		*to_end = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prv = NULL;
}

void	ft_rotate(t_nlst **head, t_nlst **end)
{
	if (*head == NULL || *end == NULL)
		return ;
	(*end)->next = *head;
	(*head)->prv = *end;
	*head = (*head)->next;
	(*head)->prv = NULL;
	*end = (*end)->next;
	(*end)->next = NULL;
}

void	ft_reverse_rotate(t_nlst **head, t_nlst **end)
{
	if (*head == NULL || *end == NULL || (*end)->prv == NULL)
		return ;
	(*head)->prv = *end;
	(*end)->next = *head;
	*head = *end;
	(*end) = (*end)->prv;
	(*end)->next = NULL;
	(*head)->prv = NULL;
}
