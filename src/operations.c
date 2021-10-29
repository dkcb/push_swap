/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:33 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 18:29:41 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sa(struct s_data *data)
{
	if (size_stack(&data->heada) > 1)
	{
		ft_putstring("sa\n");
		paste(&data->heada, cut(&data->heada, 0), 1);
	}
}

void sb(struct s_data *data)
{
		
	if (size_stack(&data->headb) > 1)
	{
		ft_putstring("sb\n");
		paste(&data->headb, cut(&data->headb, 0), 1);
	}
}

void ss(struct s_data *data)
{
	ft_putstring("ss\n");
	if (size_stack(&data->heada) > 1)
		paste(&data->heada, cut(&data->heada, 0), 1);
	if (size_stack(&data->headb) > 1)
		paste(&data->headb, cut(&data->headb, 0), 1);
}

void pa(struct s_data *data)
{
	struct s_node *tmp;

	ft_putstring("pa\n");
	if (data->headb)
	{
		tmp = cut(&data->headb, 0);
		if (data->heada == NULL)
		{
			tmp->next = tmp;
			tmp->prev = tmp;
			data->heada = tmp;
			return ;
		}
		paste(&data->heada, tmp, 0);
	}
}

void pb(struct s_data *data)
{
	struct s_node *tmp;

	ft_putstring("pb\n");
	if (data->heada)
	{
		tmp = cut(&data->heada, 0);
		if (data->headb == NULL)
		{
			tmp->next = tmp;
			tmp->prev = tmp;
			data->headb = tmp;
			return ;
		}
		paste(&data->headb, tmp, 0);
	}
}

void ra(struct s_data *data)
{
	ft_putstring("ra\n");
	if (data->heada)
		data->heada = data->heada->next;
}

void rb(struct s_data *data)
{
	ft_putstring("rb\n");
	if (data->headb)
		data->headb = data->headb->next;
}

void rr(struct s_data *data)
{
	ft_putstring("rr\n");
	if (data->heada)
		data->heada = data->heada->next;
	if (data->headb)
		data->headb = data->headb->next;
}

void rra(struct s_data *data)
{
	ft_putstring("rra\n");
	if (data->heada)
		data->heada = data->heada->prev;
}

void rrb(struct s_data *data)
{
	ft_putstring("rrb\n");
	if (data->headb)
		data->headb = data->headb->prev;
}

void rrr(struct s_data *data)
{
	ft_putstring("rrr\n");
	if (data->heada)
		data->heada = data->heada->prev;
	if (data->headb)
		data->headb = data->headb->prev;
}

// int a = 5; // an integer, contains value
// int *p; // an integer pointer, contains address
// p = &a; // &a means address of a
// a = *p; // *p means value stored in that address, here 5
