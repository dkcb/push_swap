/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:33 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 21:30:16 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(struct s_d *d)
{
	ft_putstring("rrr\n");
	if (d->ha)
		d->ha = d->ha->pr;
	if (d->hb)
		d->hb = d->hb->pr;
}
