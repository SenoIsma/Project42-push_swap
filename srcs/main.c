#include <push_swap.h>

int	main(int argc, char **argv)
{
	char **tab;
	int i;

	i = 0;
	tab = NULL;
	printf("argc = %i\n", argc);
	if (argc == 1)
		return(write(2, "Error : number of argument\n", 27), 1);
	else if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
	}
	else
	{
		tab = malloc(sizeof(char *) * argc);
		if (!tab)
			return (write(2, "Error : malloc failed\n", 23), 1);
		while (argv[i + 1])
		{
			tab[i] = argv[i + 1];
			i++;
		}
		tab[i] = NULL;
	}

	i = 0;
	while (tab[i])
	{
		printf("tab[%i] = %s\n", i, tab[i]);
		i++;
	}
	return (0);
}