/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:39:25 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/07 15:05:13 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
/*char	f(unsigned int s, char d)
{
	return (s + d);
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		new = (char *)malloc(sizeof(char) * (i + 1));
		if (new == 0)
			return (0);
		i = 0;
		while (s[i])
		{
			new [i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
/*int main()
{
	char const s1[] = "abdel";
	printf ("%s", ft_strmapi(s1, f));
}*/
