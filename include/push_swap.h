/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:56:29 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/08 16:09:50 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define NO_MED 2147483648

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pslst
{
	int				n;
	struct s_pslst	*next;
	struct s_pslst	*prv;
}					t_nlst;

typedef struct s_stack
{
	t_nlst			*head;
	t_nlst			*end;
	t_nlst			**p;
	int				top;
	int				ac;
}					t_stack;
void free_split(char **v);
void exit_error_all(t_stack *a, t_stack *b, char **split, char **argv_fake);

int			check_only_numbers(int ac, char **av);
void		error_exit(void);
int		add_node(char *str, t_nlst **end);
int			check_double(t_stack *a);
void		solver(t_stack *a, t_stack *b);
int			sorted(t_stack *a);
int			split_a_to_b(t_stack *a, t_stack *b);
void		sort_int_tab(int *tab, unsigned int size);
int			get_count(t_stack *stack);
int			get_true_median(t_stack *a);
int			get_special_median(t_stack *a);
int		build_stack(t_stack *a, int ac, char **av);
void		split_arround_med(t_stack *a, t_stack *b, int median);
int			deal_higher_nb_a(t_stack *a, int median, int *rewind);
void		push(t_nlst **from, t_nlst **to, t_nlst **to_end);
void		ft_rotate(t_nlst **head, t_nlst **end);
void		sort_a(t_stack *a, int count);
void		three_nb_case(t_stack *a);
void		ft_reverse_rotate(t_nlst **head, t_nlst **end);
void		swap(t_nlst **stack);
int			get_special_median_b(t_stack *b);
void		push_b(t_stack *b, t_stack *a, int count);
void		print_and_free(t_stack *a);
int			deal_lower_nb_b(t_stack *b, int med, int *rewind);
void		split_from_med_b(t_stack *a, t_stack *b, int med);
void		three_case_nb_b(t_stack *b);
void		sort_b(t_stack *b, int count);
int		add_head(t_stack *a, char **av);
int		add_partition(t_stack *a, t_stack *b);
void		free_all(t_stack *a);
#endif
