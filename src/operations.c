/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:33 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 19:54:32 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(struct s_d *d)
{
	if (size_stack(&d->ha) > 1)
	{
		ft_putstring("sa\n");
		paste(&d->ha, cut(&d->ha, 0), 1);
	}
}

void	sb(struct s_d *d)
{
	if (size_stack(&d->hb) > 1)
	{
		ft_putstring("sb\n");
		paste(&d->hb, cut(&d->hb, 0), 1);
	}
}

void	ss(struct s_d *d)
{
	ft_putstring("ss\n");
	if (size_stack(&d->ha) > 1)
		paste(&d->ha, cut(&d->ha, 0), 1);
	if (size_stack(&d->hb) > 1)
		paste(&d->hb, cut(&d->hb, 0), 1);
}

void	pa(struct s_d *d)
{
	struct s_node	*tmp;

	ft_putstring("pa\n");
	if (d->hb)
	{
		tmp = cut(&d->hb, 0);
		if (d->ha == NULL)
		{
			tmp->nx = tmp;
			tmp->pr = tmp;
			d->ha = tmp;
			return ;
		}
		paste(&d->ha, tmp, 0);
	}
}

void	pb(struct s_d *d)
{
	struct s_node	*tmp;

	ft_putstring("pb\n");
	if (d->ha)
	{
		tmp = cut(&d->ha, 0);
		if (d->hb == NULL)
		{
			tmp->nx = tmp;
			tmp->pr = tmp;
			d->hb = tmp;
			return ;
		}
		paste(&d->hb, tmp, 0);
	}
}

void	ra(struct s_d *d)
{
	ft_putstring("ra\n");
	if (d->ha)
		d->ha = d->ha->nx;
}

void	rb(struct s_d *d)
{
	ft_putstring("rb\n");
	if (d->hb)
		d->hb = d->hb->nx;
}

void	rr(struct s_d *d)
{
	ft_putstring("rr\n");
	if (d->ha)
		d->ha = d->ha->nx;
	if (d->hb)
		d->hb = d->hb->nx;
}

void	rra(struct s_d *d)
{
	ft_putstring("rra\n");
	if (d->ha)
		d->ha = d->ha->pr;
}

void	rrb(struct s_d *d)
{
	ft_putstring("rrb\n");
	if (d->hb)
		d->hb = d->hb->pr;
}

void	rrr(struct s_d *d)
{
	ft_putstring("rrr\n");
	if (d->ha)
		d->ha = d->ha->pr;
	if (d->hb)
		d->hb = d->hb->pr;
}
