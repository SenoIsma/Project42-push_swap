#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				signe;
	int				r;

	r = 0;
	signe = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * signe);
}
long ft_atol(const char *nptr)
{
	unsigned int	i;
	int				signe;
	long			r;

	r = 0;
	signe = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * signe);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}