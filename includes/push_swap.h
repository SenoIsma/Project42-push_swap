/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:40:59 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 12:08:33 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX		100000

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum e_error
{
	SUCCESS = 0,
	ERROR_ARGS_NUMBER = 1,
	ERROR_ARGS_EMPTY = 2,
	ERROR_PARSING = 3,
	ERROR_INIT = 4,
	ERROR_ALGO = 5,
	ERROR_MALLOC = 6,
	ERROR_NUMBER = 7,
	ERROR_CHECKER = 8
};

enum e_type
{
	RA_RB,
	RRA_RRB,
	RA_RRB,
	RRA_RB
};

enum e_mode
{
	MODE_RA,
	MODE_RRA
};

typedef struct s_info
{
	int	size;
	int	min;
	int	max;
	int	med;

}	t_info;

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_move;

typedef struct s_node
{
	int		*node_a;
	int		*node_b;
	t_info	info;
	t_info	info_a;
	t_info	info_b;
}	t_node;

//ft_clear.c
void	ft_clear(t_node *stack);
void	ft_free(void **ptr);
void	ft_free_taab(char **tab);

//ft_found.c
int		calculate_rrr_or_rr(int a, int b);
int		found_nb_ra(t_node *stack, int value);
int		found_index(int value, int *tab, int size);
t_move	found_best_move(t_node *stack, t_move *move);
t_move	found_smallest_combo(int combo[4], t_move move, t_move best_move);

//ft_info.c
int		min(int *tab, int size);
int		max(int *tab, int size);
int		make_info(t_info *info, int *tab, int size, int i);
void	update_info(t_node *stack, int i);

//ft_move.c
void	do_rrr_rr_move(t_node *stack, t_move *move);
void	do_move(t_node *stack, t_move move);
void	choose_move(t_node *stack);

//ft_sort.c
int		is_sorted(t_node *stack);
void	sort_with_median(t_node *stack);
void	sort_size_3(t_node *stack);
void	sort_size_5(t_node *stack);
void	sort_size_n(t_node *stack);

//ft_split.c
char	**ft_split(char const *s, char c);

//ft_verif.c
int		is_a_valid_char(char c);
int		all_is_number(char **strs);
int		is_duplicate(int *tab, int nb_nbrs);

//main.c
int		ft_position(int *sorted_tab, int nb, int size);
int		ft_init(t_node *stack, int *tab, int size);
void	algo_5(t_node *stack);
int		ft_algo(t_node *stack);

//mouvements.c
void	swap_int(int *a, int *b);
void	push(int *to_push, int *to_receve, int *size_push, int *size_receve);
void	pa(t_node *stack, int print);
void	pb(t_node *stack, int print);
void	rotate(int *stack, int size);

//mouvements2.c
void	rrb(t_node *stack, int print);
void	rrr(t_node *stack, int print);
void	sa(t_node *stack, int print);
void	sb(t_node *stack, int print);
void	ss(t_node *stack, int print);

//mouvements3.c
void	ra(t_node *stack, int print);
void	rb(t_node *stack, int print);
void	rr(t_node *stack, int print);
void	rotate_reverse(int *stack, int size);
void	rra(t_node *stack, int print);

//parsing.c
char	*ft_strjoin(char const *s1, char const *s2);
int		*create_tab(char **strs);
void	bubble_sort(int *tab, int size, int sorted_tab[500]);
char	*make_one(char **argv, int argc);
int		*parsing(char **argv, int argc, int *size);

//utils.c
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif