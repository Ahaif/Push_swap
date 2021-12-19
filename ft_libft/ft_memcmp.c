/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:57:39 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/07 14:59:12 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str_s1;
	const unsigned char	*str_s2;
	size_t				i;

	str_s1 = (const unsigned char *)s1;
	str_s2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str_s1[i] != str_s2[i])
			return (str_s1[i] - str_s2[i]);
		i++;
	}
	return (0);
}
