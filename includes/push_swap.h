#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR_ARG 1
# define ERROR_MALLOC 2
# define ERROR_INT 3

typedef struct s_data
{
	int		*tab;
	size_t	size;
}	t_data;

typedef struct s_info
{
	int	size;
	int	min;
	int	max;
	int	med;

}	t_info;

typedef struct s_node
{
	int *node_a;
	int *node_b;
	t_info	info_a;
	t_info	info_b;
}	t_node;

void	ft_error(char *str, int error);
char	**ft_split(char const *s, char c);

//Utils
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_free_tab(char **tab);

//ft_verif
int		verif_int(char **strs);
int		verif_integer(char *str);
void	verif_double(t_data *data);
//Handle errors

//stack initiation 

//Nodes Initiations

//Stack utils 

//Commands

//Algo




#endif