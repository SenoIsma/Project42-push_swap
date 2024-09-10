/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:52:14 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:58:45 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_node *stack, int print)
{
	if (stack->info_a.size >= 1)
	{
		rotate(stack->node_a, stack->info_a.size);
		if (print == TRUE)
			write(1, "ra\n", 3);
	}
}

void	rb(t_node *stack, int print)
{
	if (stack->info_b.size >= 1)
	{
		rotate(stack->node_b, stack->info_b.size);
		if (print == TRUE)
			write(1, "rb\n", 3);
	}
}

void	rr(t_node *stack, int print)
{
	if (stack->info_a.size >= 1 && stack->info_b.size >= 1)
	{
		ra(stack, FALSE);
		rb(stack, FALSE);
		if (print == TRUE)
			write(1, "rr\n", 3);
	}
}

void	rotate_reverse(int *stack, int size)
{
	int	tmp;
	int	i;

	i = size - 1;
	tmp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rra(t_node *stack, int print)
{
	if (stack->info_a.size >= 1)
	{
		rotate_reverse(stack->node_a, stack->info_a.size);
		if (print == TRUE)
			write(1, "rra\n", 4);
	}
}
