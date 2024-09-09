/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:20:31 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/09 11:44:53 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	push(int *to_push, int *to_receve, int *size_push, int *size_receve)
{
	const int	size = *size_push + *size_receve;
	int			tmp_top;
	int			i;

	tmp_top = to_push[0];
	to_push[0] = 0;
	i = -1;
	while (++i < *size_push)
		if (i + 1 < size)
			to_push[i] = to_push[i + 1];
	*size_push -= 1;
	*size_receve += 1;
	i = *size_receve + 1;
	while (--i > 0)
		if (i < size && i - 1 >= 0)
			to_receve[i] = to_receve[i - 1];
	to_receve[0] = tmp_top;
}

void	pa(t_node *stack, int print)
{
	if (stack->info_b.size > 0)
	{
		push(stack->node_b, stack->node_a, &stack->info_b.size, &stack->info_a.size);
		if (print == TRUE)
			write(1, "pa\n", 3);
	}
}

void	pb(t_node *stack, int print)
{
	if (stack->info_a.size > 0)
	{
		push(stack->node_a, stack->node_b, &stack->info_a.size, &stack->info_b.size);
		if (print == TRUE)
			write(1, "pb\n", 3);
	}
}

void	rotate(int *stack, int size)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

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