/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:29:22 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/07 15:03:55 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	str_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (s1 && s2)
	{	
		k = 0;
		i = 0;
		j = str_len(s1) + str_len(s2);
		new = (char *)malloc(sizeof(char) * (j + 1));
		if (new == 0)
			return (0);
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		k = 0;
		while (s2[k])
			new[i++] = s2[k++];
		new[i] = '\0';
		return (new);
	}
	return (0);
}

/*int main()
{
	char const s1[] = "abdel";
	char const s2[] = " ";

	printf("%s", ft_strjoin(s1, s2));
}*/
