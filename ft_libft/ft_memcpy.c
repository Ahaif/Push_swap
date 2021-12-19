/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:22:05 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/07 14:57:53 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*str_src;
	unsigned char		*str_dst;
	unsigned int		i;

	i = 0;
	str_src = (const unsigned char *)src;
	str_dst = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
