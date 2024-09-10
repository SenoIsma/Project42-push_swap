/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:47:22 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:48:21 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_valid_char(char c)
{
	const char	valid_chars[] = "0123456789+-";
	int			i;

	i = 0;
	while (valid_chars[i])
	{
		if (c == valid_chars[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	all_is_number(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!is_a_valid_char(strs[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_duplicate(int *tab, int nb_nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_nbrs)
	{
		j = i + 1;
		while (j < nb_nbrs)
		{
			if (tab[i] == tab[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
