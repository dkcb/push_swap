/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:33 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 21:29:51 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
