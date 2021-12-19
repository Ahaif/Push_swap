/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:01:39 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/06 09:42:08 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*int	main()
{
	int tab[5] = {1, 2, 3, 4};

	int p;

	bzero(tab, 5 * sizeof(int));
	p = 0;

	while (p < 5)
	{
		printf("%d", tab[p]);
		p++;
	}
}*/
