/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:54:43 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/06 13:01:39 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize < 1)
		return (i);
	while ((j < dstsize - 1) && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
/*int main()
{
	char dst[] = "abdel";
	const char src[] = "";
   	size_t l = 0;

	printf("%lu\n", strlcpy(dst, src, l));
	printf("%zu", ft_strlcpy(dst, src, l));
	}*/
