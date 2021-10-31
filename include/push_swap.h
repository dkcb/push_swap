/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:55 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/31 19:00:14 by dkocob        ########   odam.nl         */
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
	int				i;
	struct s_node	*nx;
	struct s_node	*pr;
};

struct s_d
{
	void			(*fun_ptr_arr[1100])(struct s_d *d);
	int				argc;
	int				*intlist;
	int				*sintlist;
	char			**a;
	struct s_node	*ha;
	struct s_node	*hb;
};

void			assign(struct s_d *d);
void			pa(struct s_d *d);
void			pb(struct s_d *d);
void			sa(struct s_d *d);
void			sb(struct s_d *d);
void			ss(struct s_d *d);
void			ra(struct s_d *d);
void			rb(struct s_d *d);
void			rr(struct s_d *d);
void			rra(struct s_d *d);
void			rrb(struct s_d *d);
void			rrr(struct s_d *d);
int				ft_isdigit(char c);
void			ft_putstring(char *s);
int				check_input(struct s_d *d, int i, int i2);
int				ft_exit(struct s_d *d, int fl);
int				distance(struct s_node *head, int index, int r, int rr);
int				distance_range(struct s_node *head, int min, int max);
int				sorted_int(struct s_d *d, int i, int tmp);
int				unsorted_int(struct s_d *d, int i);
int				sort(struct s_d *d);
int				size_stack(struct s_node **head);
int				ordered(struct s_node *n);
void			printlist(struct s_d *d);
int				get_arg_stack(struct s_d *d);
long			val(char *s);
struct s_node	*cut(struct s_node **head, int pos);
struct s_node	*paste(struct s_node **head, struct s_node *node, int pos);

#endif
