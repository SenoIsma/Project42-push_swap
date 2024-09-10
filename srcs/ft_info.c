/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:35:32 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:46:37 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	min(int *tab, int size)
{
	int	min;
	int	i;

	min = tab[0];
	i = 0;
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	max(int *tab, int size)
{
	int	max;
	int	i;

	max = tab[0];
	i = 0;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	make_info(t_info *info, int *tab, int size, int i)
{
	int	sorted_tab[500];

	info->size = size;
	info->min = min(tab, size);
	info->max = max(tab, size);
	if (i == 1)
	{
		ft_bzero(sorted_tab, 500);
		bubble_sort(tab, size, sorted_tab);
		info->med = sorted_tab[size / 2];
	}
	else
		info->med = -1;
	return (SUCCESS);
}

void	update_info(t_node *stack, int i)
{
	if (make_info(&stack->info_a, stack->node_a, stack->info_a.size, i))
		return (ft_clear(stack), write(2, "Error : update_info\n", 20), \
		exit(ERROR_NUMBER));
	if (make_info(&stack->info_b, stack->node_b, stack->info_b.size, i))
		return (ft_clear(stack), write(2, "Error : update_info\n", 20), \
		exit(ERROR_NUMBER));
}
