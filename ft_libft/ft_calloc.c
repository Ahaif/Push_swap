/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:09 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/09 17:56:54 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = count * size;
	new = malloc(i);
	if (new == NULL)
		return (NULL);
	while (i > 0)
	{
		new[j] = 0;
		j++;
		i--;
	}
	return (new);
}
