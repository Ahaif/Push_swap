/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:35:21 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/06 12:39:45 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - s2[i]);
}
/*int main ()
{
	const char s1[] = "abbdsfbcf";
	const char s2[] = "abfsdbcf";
	size_t n = 2; 

	printf("%d\n", strncmp(s1, s2, n));
	printf("%d", ft_strncmp(s1, s2, n));
}*/
