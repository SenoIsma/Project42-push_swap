/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:35:07 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/09/10 11:55:33 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	*create_tab(char **strs)
{
	int	i;
	int	*tab;

	i = 0;
	while (strs[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		if (ft_atoi(strs[i]) != ft_atol(strs[i]))
			return (free(tab), NULL);
		tab[i] = ft_atoi(strs[i]);
		i++;
	}
	if (is_duplicate(tab, i) == TRUE)
		return (free(tab), NULL);
	return (tab);
}

void	bubble_sort(int *tab, int size, int sorted_tab[500])
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
		sorted_tab[i] = tab[i];
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (sorted_tab[j] < sorted_tab[j - 1])
				swap_int(&sorted_tab[j], &sorted_tab[j - 1]);
			j--;
		}
		i++;
	}
}

char	*make_one(char **argv, int argc)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = ft_strjoin(argv[0], " ");
	if (!str)
		return (NULL);
	while (i < argc && argv[i])
	{
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		if (!str)
			return (NULL);
		free(tmp);
		i++;
	}
	return (str);
}

int	*parsing(char **argv, int argc, int *size)
{
	int		*tab;
	char	*str;
	char	**strs;
	int		i;

	i = 0;
	str = make_one(argv, argc);
	if (!str)
		return (NULL);
	strs = ft_split(str, ' ');
	if (!strs)
		return (free(str), NULL);
	free(str);
	if (all_is_number(strs) == FALSE)
		return (ft_free_taab(strs), NULL);
	tab = create_tab(strs);
	if (!tab)
		return (ft_free_taab(strs), NULL);
	while (strs[i])
		i++;
	*size = i;
	ft_free_taab(strs);
	return (tab);
}
