/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlel <ibouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:38:37 by ibouhlel          #+#    #+#             */
/*   Updated: 2024/07/05 15:44:48 by ibouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (FALSE);
	return (TRUE);
}
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (FALSE);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (FALSE);
	if (have_duplicates(av))
		return (FALSE);
	return (TRUE);
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return (ERROR_ARG);
	if (argc == 2)
	{
		if (ft_checker(argv[1]) == FALSE)
			return (ERROR_CHECKER);
		
	}
	else
	{
	}
	
}


