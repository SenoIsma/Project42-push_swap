/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:04:29 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:50:41 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_position(int *sorted_tab, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_tab[i] == nb)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_init(t_node *stack, int *tab, int size)
{
	int	i;
	int	sorted_tab[500];

	ft_bzero(sorted_tab, 500);
	stack->node_a = ft_calloc(size, sizeof(t_node));
	if (!stack->node_a)
		return (free(tab), EXIT_FAILURE);
	stack->node_b = ft_calloc(size, sizeof(t_node));
	if (!stack->node_b)
		return (free(tab), EXIT_FAILURE);
	if (size > 500)
		return (free(tab), EXIT_FAILURE);
	bubble_sort(tab, size, sorted_tab);
	i = 0;
	while (i < size)
	{
		stack->node_a[i] = ft_position(sorted_tab, tab[i], size);
		i++;
	}
	stack->info = (t_info){size, 1, size, sorted_tab[size / 2]};
	stack->info_a = (t_info){size, 1, size, sorted_tab[size / 2]};
	stack->info_b = (t_info){0, 0, 0, 0};
	free(tab);
	return (SUCCESS);
}

void	algo_5(t_node *stack)
{
	int	i;
	int	use;

	i = 0;
	if (found_index(1, stack->node_a, stack->info_a.size) < \
	stack->info_a.size / 2)
		use = 1;
	else
		use = 0;
	while (stack->info_a.size != 3)
	{
		if (stack->node_a[0] == i + 1)
		{
			pb(stack, TRUE);
			if (found_index(++i + 1, stack->node_a, stack->info_a.size) < \
			stack->info_a.size / 2)
				use = 1;
			else
				use = 0;
		}
		else if (use == 1)
			ra(stack, TRUE);
		else
			rra(stack, TRUE);
	}
}

int	ft_algo(t_node *stack)
{
	if (is_sorted(stack) == TRUE)
		return (SUCCESS);
	if (stack->info.size == 2)
		sa(stack, TRUE);
	else if (stack->info.size <= 3)
		sort_size_3(stack);
	else if (stack->info.size <= 5)
		sort_size_5(stack);
	else
		sort_size_n(stack);
	if (is_sorted(stack) == TRUE)
		return (SUCCESS);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		*tab;
	t_node	stack;
	int		size;
	int		i;

	i = 0;
	ft_bzero(&stack, sizeof(t_node));
	if (argc < 2)
		return (write(2, "Error : No arguments\n", 21), ERROR_ARGS_NUMBER);
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		return (write(2, "Error : Empty arguments\n", 25), ERROR_ARGS_EMPTY);
	tab = parsing(&argv[1], argc - 1, &size);
	if (!tab)
		return (write(2, "Error: Parsing\n", 16), ERROR_PARSING);
	if (ft_init(&stack, tab, size) == ERROR_INIT)
		return (write(2, "Error : Initialisation\n", 24), ft_clear(&stack), \
		ERROR_INIT);
	if (ft_algo(&stack) == ERROR_ALGO)
		return (write(2, "Error : Algorithme\n", 20), ft_clear(&stack), \
		ERROR_ALGO);
	ft_clear(&stack);
	return (SUCCESS);
}
