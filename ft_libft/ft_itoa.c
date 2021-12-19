/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:23:41 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/07 14:34:43 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static long	get_len(long nb)
{
	long	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long		nb;
	long		i;
	char		*new;

	nb = n;
	i = get_len(nb);
	new = (char *)malloc(sizeof (char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i--;
	if (nb < 0)
	{
		new[0] = '-';
		nb = nb * -1;
	}
	while (nb > 9)
	{
		new [i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	new[i] = nb + 48;
	return (new);
}
/*int main()
{
	int nb = 154;
	printf("%s\n", ft_itoa(nb));
}*/
