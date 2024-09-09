#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum e_error
{
	SUCCESS = 0,
	ERROR_ARGS_NUMBER = 1,
	ERROR_ARGS_EMPTY = 2,
	ERROR_PARSING = 3,
	ERROR_INIT = 4,
	ERROR_ALGO = 5,
	ERROR_MALLOC = 6,
	ERROR_NUMBER = 7,
	ERROR_CHECKER = 8
};

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
	t_info	info;
	t_info	info_a;
	t_info	info_b;
}	t_node;

//ft_clear.c

void	ft_clear(t_node *stack);
void	ft_free(void **ptr);
void	ft_free_taab(char **tab);

//ft_split.c

char	**ft_split(char const *s, char c);

//ft_verif.c

int		is_a_valid_char(char c);
int 	all_is_number(char **strs);
int		is_duplicate(int *tab, int nb_nbrs);

//main.c

int		ft_position(int *sorted_tab, int nb, int size);
int		ft_init(t_node *stack, int *tab, int size);

//mouvements.c

void	swap_int(int *a, int *b);

//parsing.c

char	*ft_strjoin(char const *s1, char const *s2);
int		*create_tab(char **strs);
void	bubble_sort(int *tab, int size, int sorted_tab[500]);
char	*make_one(char **argv, int argc);
int		*parsing(char **argv, int argc, int *size);

//utils.c

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif