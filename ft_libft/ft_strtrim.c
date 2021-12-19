/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:32:30 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/06 17:49:18 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	if (s1)
	{
		i = 0;
		k = 0;
		j = ft_strlen(s1);
		while (check_set(s1[i], set))
			i++;
		j--;
		while (j > i && check_set(s1[j], set))
			j--;
		new = (char *)malloc(sizeof(char) * (j - i) + 2);
		if (new == 0)
			return (0);
		while (s1[i] && i <= j)
			new[k++] = s1[i++];
		new [k] = '\0';
		return (new);
	}
	return (0);
}		
/*int main()
{
	 char const str[] = "obodel haifo";
	 char const set[] = "io";

	 printf("%s\n", ft_strtrim(str, set));
}*/
