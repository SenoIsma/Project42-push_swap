/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:30:25 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:57:20 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	int	i;

	if (stack->info_b.size != 0)
		return (FALSE);
	i = 0;
	while (i < stack->info_a.size)
	{
		if (stack->node_a[i] != i + 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	sort_with_median(t_node *stack)
{
	while (stack->info_a.size != 3)
	{
		if (stack->info_a.med <= stack->node_a[0])
		{
			pb(stack, TRUE);
			if (stack->info_a.med == stack->node_b[0])
				update_info(stack, 1);
		}
		else
			ra(stack, TRUE);
	}
}

void	sort_size_3(t_node *stack)
{
	if (stack->node_a[0] == stack->info_a.min)
	{
		if (stack->node_a[1] == stack->info_a.max)
		{
			sa(stack, TRUE);
			ra(stack, TRUE);
		}
	}
	else if (stack->node_a[0] == stack->info_a.max)
	{
		if (stack->node_a[1] == stack->info_a.min)
			ra(stack, TRUE);
		else
		{
			sa(stack, TRUE);
			rra(stack, TRUE);
		}
	}
	else
	{
		if (stack->node_a[1] == stack->info_a.min)
			sa(stack, TRUE);
		else
			rra(stack, TRUE);
	}
}

void	sort_size_5(t_node *stack)
{
	algo_5(stack);
	update_info(stack, 1);
	sort_size_3(stack);
	while (stack->info_b.size != 0)
		pa(stack, TRUE);
}

void	sort_size_n(t_node *stack)
{
	int	use;

	update_info(stack, 1);
	sort_with_median(stack);
	update_info(stack, 1);
	sort_size_3(stack);
	while (stack->info_b.size != 0)
	{
		update_info(stack, 0);
		choose_move(stack);
	}
	update_info(stack, 1);
	if (found_index(stack->info.min, stack->node_a, stack->info_a.size) < \
	stack->info_a.med)
		use = MODE_RA;
	else
		use = MODE_RRA;
	while (stack->node_a[0] != stack->info_a.min)
	{
		if (use == MODE_RA)
			ra(stack, TRUE);
		else
			rra(stack, TRUE);
	}
}
