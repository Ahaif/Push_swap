/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:30:23 by abhaifou          #+#    #+#             */
/*   Updated: 2025/08/27 10:30:29 by abhaifou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char **v)
{
	int	n;

	n = 0;
	if (!v)
		return (0);
	while (v[n])
		n++;
	return (n);
}

void	free_split(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

static char	**make_argv_fake(char **av, char **split, int n)
{
	int		i;
	char	**fake;

	fake = (char **)malloc(sizeof(char *) * (n + 2));
	if (!fake)
		exit_error_all(NULL, NULL, split, NULL);
	fake[0] = av[0];
	i = 0;
	while (i < n)
	{
		fake[i + 1] = split[i];
		i++;
	}
	fake[n + 1] = NULL;
	return (fake);
}

int	prepare_argv(int *ac, char ***av, char ***split_out, char ***argv_fake_out)
{
	int		n;
	char	**split;
	char	**fake;

	*split_out = NULL;
	*argv_fake_out = NULL;
	if (*ac != 2)
		return (1);
	split = ft_split((*av)[1], ' ');
	if (!split)
		exit_error_all(NULL, NULL, NULL, NULL);
	n = count_tokens(split);
	if (n == 0)
	{
		free_split(split);
		return (0);
	}
	fake = make_argv_fake(*av, split, n);
	*av = fake;
	*ac = n + 1;
	*split_out = split;
	*argv_fake_out = fake;
	return (1);
}
