/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:51:18 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:58:41 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rrb(t_node *stack, int print)
{
	if (stack->info_b.size >= 1)
	{
		rotate_reverse(stack->node_b, stack->info_b.size);
		if (print == TRUE)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_node *stack, int print)
{
	if (stack->info_a.size >= 1 && stack->info_b.size >= 1)
	{
		rotate_reverse(stack->node_a, stack->info_a.size);
		rotate_reverse(stack->node_b, stack->info_b.size);
		if (print == TRUE)
			write(1, "rrr\n", 4);
	}
}

void	sa(t_node *stack, int print)
{
	if (stack->info_a.size > 1)
	{
		swap_int(&stack->node_a[0], &stack->node_a[1]);
		if (print == TRUE)
			write(1, "sa\n", 3);
	}
}

void	sb(t_node *stack, int print)
{
	if (stack->info_b.size > 1)
	{
		swap_int(&stack->node_b[0], &stack->node_b[1]);
		if (print == TRUE)
			write(1, "sb\n", 3);
	}
}

void	ss(t_node *stack, int print)
{
	if (stack->info_a.size > 1 && stack->info_b.size > 1)
	{
		sa(stack, FALSE);
		sb(stack, FALSE);
		if (print)
			write(1, "ss\n", 3);
	}
}
