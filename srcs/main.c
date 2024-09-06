#include <push_swap.h>

void	ft_error(char *str, int error)
{
	write(2, str, ft_strlen(str));
	exit(error);
}

int main(int argc, char **argv)
{
	char **strs;
	t_data data;
	int i;

	i = 0;
	ft_bzero(&data, sizeof(t_data));
	if (argc < 2)
		return (ERROR_ARG);
	else if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs)
			return (write(2, "Error : Malloc failed\n", 22), ERROR_MALLOC);
		while (strs[i])
			i++;
		data.size = i;
		verif_int(strs);
		data.tab = malloc(sizeof(int) * (data.size + 1));
		if (!data.tab)
			return (write(2, "Error : Malloc failed\n", 22), ft_free_tab(strs), ERROR_MALLOC);
		i = 0;
		while (strs[i])
		{
			if (ft_atoi(strs[i]) != ft_atol(strs[i]))
			{
				ft_free_tab(strs);
				ft_error("Error : overflow\n", ERROR_INT);
			}
			data.tab[i] = ft_atoi(strs[i]);
			i++;
		}
		ft_free_tab(strs);
		verif_double(&data);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			verif_integer(argv[i]);
			i++;
		}
		data.size = argc - 1;
		data.tab = malloc(sizeof(int) * (data.size + 1));
		if (!data.tab)
			return (write(2, "Error : Malloc failed\n", 22), ERROR_MALLOC);
		i = 1;
		while (argv[i])
		{
			if (ft_atoi(argv[i]) != ft_atol(argv[i]))
			{
				free(data.tab);
				ft_error("Error : overflow\n", ERROR_INT);
			}
			data.tab[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		verif_double(&data);
	}
	i = 0;
	while ((size_t)i < data.size)
	{
		printf("%d\n", data.tab[i]);
		i++;
	}
	free(data.tab);
	return (SUCCESS);
}
