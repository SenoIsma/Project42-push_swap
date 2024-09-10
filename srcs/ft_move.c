/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:36:03 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:58:29 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr_rr_move(t_node *stack, t_move *move)
{
	while (move->rra > 0 && move->rrb > 0)
	{
		rrr(stack, TRUE);
		move->rra--;
		move->rrb--;
	}
	while (move->ra > 0 && move->rb > 0)
	{
		rr(stack, TRUE);
		move->ra--;
		move->rb--;
	}
}

void	do_move(t_node *stack, t_move move)
{
	do_rrr_rr_move(stack, &move);
	while (move.ra > 0)
	{
		ra(stack, TRUE);
		move.ra--;
	}
	while (move.rb > 0)
	{
		rb(stack, TRUE);
		move.rb--;
	}
	while (move.rra > 0)
	{
		rra(stack, TRUE);
		move.rra--;
	}
	while (move.rrb > 0)
	{
		rrb(stack, TRUE);
		move.rrb--;
	}
	pa(stack, TRUE);
}

void	choose_move(t_node *stack)
{
	t_move		*move;
	t_move		doit;
	int			i;

	move = (t_move *)ft_calloc(stack->info_b.size, sizeof(t_move));
	if (!move)
		return (write(2, "Error : malloc failed\n", 23), ft_clear(stack), \
		exit(ERROR_MALLOC));
	i = 0;
	while (i < stack->info_b.size)
	{
		move[i] = (t_move)
		{
			.ra = found_nb_ra(stack, stack->node_b[i]),
			.rb = i,
			.rra = stack->info_a.size - found_nb_ra(stack, stack->node_b[i]),
			.rrb = stack->info_b.size - i
		};
		i++;
	}
	doit = found_best_move(stack, move);
	do_move(stack, doit);
	free(move);
}
