/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:20:02 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/06 13:29:30 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0' && (i + j) < n)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
/*int main()
{
	char s1[] = "addeldled";
	char s2[] = "el";
	size_t n = 5;

	printf("%s\n", strnstr(s1, s2, n));
	printf("%s\n", ft_strnstr(s1, s2, n));
}*/
