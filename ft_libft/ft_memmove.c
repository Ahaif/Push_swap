/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:26:46 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/08 13:58:26 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*str_dst;
	char			*str_src;
	unsigned int	i;

	str_dst = (char *)dst;
	str_src = (char *)src;
	i = 0;
	if (str_dst > str_src)
	{
		while (len-- > 0)
			str_dst[len] = str_src[len];
	}
	else
	{	
		ft_memcpy(str_dst, str_src, len);
	}
	return (dst);
}
