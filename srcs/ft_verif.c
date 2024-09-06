#include "push_swap.h"

int verif_int(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if ((strs[i][j] < '0' || strs[i][j] > '9') && strs[i][j] != '-')
			{
				ft_free_tab(strs);
				ft_error("Error : Not a number\n", ERROR_INT);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
int verif_integer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		{
			ft_error("Error : Not a number\n", ERROR_INT);
		}
		i++;
	}
	return (SUCCESS);
}
void	verif_double(t_data *data)
{
	int i;
	int j;

	i = 0;
	while ((size_t)i < data->size)
	{
		j = i + 1;
		while ((size_t)j < data->size)
		{
			if (data->tab[i] == data->tab[j])
			{
				free(data->tab);
				ft_error("Error : Double\n", ERROR_INT);
			}
			j++;
		}
		i++;
	}
}