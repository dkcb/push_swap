/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorythm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 19:52:24 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_swap_hab(struct s_d *d, char c)
{
	if (c == 'b' && d->hb && d->hb->i < d->hb->nx->i)
	{
		sb(d);
		return (1);
	}
	else if (c == 'a' && d->ha && d->ha->i > d->ha->nx->i)
	{
		sa(d);
		return (1);
	}
	return (0);
}

int	sort5(struct s_d *d)
{
	while (d->ha && ordered(d->ha) < 1)
	{
		while (size_stack(&d->ha) > 3)
		{
			while (distance_range(d->ha, 0, d->argc - 4) > 0)
				ra(d);
			while (distance_range(d->ha, 0, d->argc - 4) < 0)
				rra(d);
			pb(d);
		}
		while (d->ha && ordered(d->ha) < 1)
		{
			if (d->ha && d->ha->i > d->ha->nx->i && d->ha->i < d->ha->nx->nx->i)
				sa(d);
			else if (d->ha && d->ha->i > d->ha->nx->i)
				ra(d);
			else if (d->ha && d->ha->nx->i > d->ha->nx->nx->i)
				rra(d);
		}
		if (d->hb && d->hb->i < d->hb->nx->i)
			sb(d);
		while (d->hb && size_stack(&d->hb) > 0)
			pa(d);
	}
	return (0);
}

int	push_tob_lim(struct s_d *d, int gap, int th)
{
	int	cnt;

	cnt = 0;
	while (d->ha && size_stack(&d->ha) > 0)
	{
		while (d->ha && d->ha->i < th && size_stack(&d->ha) > 0 && cnt < gap)
		{
			pb(d);
			cnt++;
			if (cnt >= gap)
			{
				cnt = 0;
				th += gap;
			}
			check_swap_hab(d, 'b');
		}
		if (size_stack(&d->ha) > 0 && check_swap_hab(d, 'b') < 1)
			ra(d);
	}
	return (0);
}

int	push_toa_lim(struct s_d *d, int dcn, int cnt, int th)
{
	while (d->hb && size_stack(&d->hb) > 0)
	{
		while (d->hb && d->hb->i >= th && size_stack(&d->hb) > 0 && cnt < 2)
		{
			pa(d);
			cnt++;
			if (cnt >= 2)
			{
				cnt = 0;
				th -= 2;
			}
			check_swap_hab(d, 'a');
		}
		dcn = distance_range(d->hb, th, th + 2);
		if (size_stack(&d->hb) > 0 && check_swap_hab(d, 'a') < 1)
		{
			if (dcn < 0)
				rrb(d);
			else if (dcn > 0)
				rb(d);
		}
	}
	return (0);
}

int	sort(struct s_d *d)
{
	if (d->ha && ordered(d->ha) < 1)
	{
		if (d->argc > 1 && d->argc <= 6)
			sort5(d);
		if (d->argc > 6 && d->argc <= 495)
			push_tob_lim(d, d->argc / 4, d->argc / 4);
		if (d->argc > 495)
			push_tob_lim(d, d->argc / 12, d->argc / 12);
		push_toa_lim(d, 0, 0, d->argc - 3);
	}
	return (0);
}
