/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:59:56 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/07 18:02:44 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof (*list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = malloc(content_size);
		if (!list->content)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
