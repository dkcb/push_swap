/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:55 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/22 15:48:11 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

struct s_node
{
	int				data;
	int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
};

struct s_data
{
	int		size_a;
	int		size_b;
	int		argc;
	int		amin;
	int		amax;
	int		bmin;
	int		bmax;
	int		indmid;
	int		*intlist;
	int		*sorted;
	char	**argv;
	struct	s_node *heada;
	struct	s_node *taila;
	struct	s_node *headb;
	struct	s_node *tailb;
};

void pa(struct s_data *data);
void pb(struct s_data *data);
void sa(struct s_data *data);
void sb(struct s_data *data);
void ss(struct s_data *data);
void ra(struct s_data *data);
void rb(struct s_data *data);
void rr(struct s_data *data);
void rra(struct s_data *data);
void rrb(struct s_data *data);
void rrr(struct s_data *data);
struct s_node *cut (struct s_node **head, int pos);
struct s_node *paste (struct s_node **head, struct s_node *node, int pos);
int		ft_isdigit(char c);
void	ft_putstring(char *s);
int		check_input(struct s_data *data);
int		ft_exit(struct s_data *data, int fl);
int		distance(struct s_node *head, int index);
int		distance_range(struct s_node *head, int min, int max);
int		sorted_int(struct s_data* data);
int		sort(struct s_data* data);
int		size_stack(struct s_node **head);
int		ordered(struct s_node *n);
void	printlist(struct s_data *data);
int		get_arg_stack(struct s_data *data);
long long		get_val(char *s);

#endif
