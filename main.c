/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:37:29 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/08 16:16:18 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_head(t_stack *a, char **av)
{
	a->head = malloc(sizeof(t_nlst));
	if (!a->head)
		return 0;
	else
	{
        if(ft_atoi(av[1]) == NO_MED)
            return (0);
		a->head->n = ft_atoi(av[1]);

		a->head->next = NULL;
		a->head->prv = NULL;
		a->end = a->head;
		return 1;
	}
}

int	add_partition(t_stack *a, t_stack *b)
{
	a->p = malloc(sizeof(t_nlst *) * a->ac);
	if (!a->p)
		return (0);
	b->p = malloc(sizeof(t_nlst *) * a->ac);
	if (!b->p)
		return (0);
	return (1);
}

void free_all(t_stack *s)
{
    if (!s) return;
    t_nlst *tmp;
    while (s->head) { tmp = s->head; s->head = s->head->next; free(tmp); }
    if (s->p) { free(s->p); s->p = NULL; }
    s->end = NULL;
    s->top = 0;
}


void exit_error_all(t_stack *a, t_stack *b, char **split, char **argv_fake)
{
    if (a) {                       // free stack A nodes + its partitions (if set)
        t_nlst *tmp;
        while (a->head) { tmp = a->head; a->head = a->head->next; free(tmp); }
        if (a->p) free(a->p), a->p = NULL;
    }
    if (b) {
        t_nlst *tmp;
        while (b->head) { tmp = b->head; b->head = b->head->next; free(tmp); }
        if (b->p) free(b->p), b->p = NULL;
    }
    if (argv_fake) free(argv_fake);   // this is the small wrapper array only
    if (split) free_split(split);     // frees all the tokens + the array

    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}


void free_split(char **v)
{
    if (!v) return;
    for (int i = 0; v[i]; i++) free(v[i]);
    free(v);
}

int main(int ac, char **av)
{
    /* zero-init so error paths are safe */
    t_stack a = {0};
    t_stack b = {0};

    char **split = NULL;
    char **argv_fake = NULL;

    if (ac < 2) return 0;

    /* Support $ARG / quoted single argument */
    if (ac == 2) {
        split = ft_split(av[1], ' ');
        if (!split) exit_error_all(NULL, NULL, NULL, NULL);

        int n = 0; while (split[n]) n++;
        if (n == 0) { free_split(split); return 0; }

        /* Need space for av[0], n tokens, and a NULL terminator -> n+2 */
        argv_fake = malloc((n + 2) * sizeof(char *));
        if (!argv_fake) exit_error_all(NULL, NULL, split, NULL);

        argv_fake[0] = av[0];
        for (int i = 0; i < n; i++) argv_fake[i + 1] = split[i];
        argv_fake[n + 1] = NULL;          /* <-- proper terminator */

        av = argv_fake;
        ac = n + 1;                        /* tokens are at av[1..ac-1] */
    }

    /* Build stack A from av[1..ac-1] */
    if (!build_stack(&a, ac, av))
        exit_error_all(&a, &b, split, argv_fake);

    /* Set sizes BEFORE add_partition (it uses a.ac) */
    a.ac = ac;
    b.ac = ac;

    if (!add_partition(&a, &b))
        exit_error_all(&a, &b, split, argv_fake);

    a.top = 0; b.top = 0;
    a.p[a.top] = NULL;
    b.p[b.top] = NULL;

    solver(&a, &b);

    /* normal cleanup */
    free_all(&a);
    free_all(&b);
    if (argv_fake) free(argv_fake);   /* free wrapper array only */
    if (split) free_split(split);     /* free the duplicated tokens */
    return 0;
}
