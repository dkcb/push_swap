/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorythm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/29 21:51:27 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_swap_hab_tob(struct s_d* d)
{
	if (d->hb && d->hb->i < d->hb->nx->i)
	{
		sb(d);
		return (1);
	}
	return (0);
}

int	check_swap_hab_toa(struct s_d* d)
{
	if (d->ha && d->ha->i > d->ha->nx->i)
	{
		sa(d);
		return(1);
	}
	return (0);
}

int	sort3(struct s_d* d)
{
	while (d->ha && ordered(d->ha) < 1)
	{
		if (d->ha && d->ha->i > d->ha->nx->i && d->ha->i < d->ha->nx->nx->i)
			sa(d);
		else if (d->ha && d->ha->i > d->ha->nx->i)
			ra(d);
		else if (d->ha && d->ha->nx->i > d->ha->nx->nx->i)
			rra(d);
	}
	return (0);
}

int	sort5(struct s_d* d)
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
		sort3(d);
		if (d->hb && d->hb->i < d->hb->nx->i)
			sb(d);
		while (d->hb && size_stack(&d->hb) > 0)
			pa(d);
	}
	return (0);
}

int push_tob_lim(struct s_d* d, int gap)
{
	int dcn;
	int cnt = 0;
	int	treshhold = gap;
	
	while (d->ha && size_stack(&d->ha) > 0)
	{
		dcn = distance_range(d->ha, treshhold - gap, treshhold);
		while (d->ha && d->ha->i < treshhold && size_stack(&d->ha) > 0 && cnt < gap)
		{
			pb(d);
			cnt++;
			if (cnt >= gap)
			{
				cnt = 0;
				treshhold += gap;
			}
			check_swap_hab_tob(d);
		}
		dcn = distance_range(d->ha, treshhold - gap, treshhold);
		if (size_stack(&d->ha) > 0 && check_swap_hab_tob(d) < 1)
		{
			// if (dcn < 0) //comm 10000
			// 	rra(d);
			// if (dcn > 0)
				ra(d);
		}
		if (cnt >= gap)
		{
			cnt = 0;
			treshhold += gap;
		}
	}
	return (0);
}

int push_toa_lim(struct s_d* d, int gap)
{
	int dcn;
	int cnt = 0;
	int	treshhold = d->argc - gap - 1;
	
	while (d->hb && size_stack(&d->hb) > 0)
	{
		// check_swap_hab_toa(d);
		dcn = distance_range(d->hb, treshhold , treshhold + gap);
		while (d->hb && d->hb->i >= treshhold && size_stack(&d->hb) > 0 && cnt < gap)
		{
			pa(d);
			cnt++;
			if (cnt >= gap)
			{
				cnt = 0;
				treshhold -= gap;
			}
			check_swap_hab_toa(d);
		}
		dcn = distance_range(d->hb, treshhold, treshhold + gap);
		if (size_stack(&d->hb) > 0 && check_swap_hab_toa(d) < 1)
		{
			if (dcn < 0)
				rrb(d);
			else if (dcn > 0)
				rb(d);
		}
		if (cnt >= gap)
		{
			cnt = 0;
			treshhold -= gap;
		}
	}
	return (0);
}

int	sort(struct s_d* d)
{
	if (d->ha && ordered(d->ha) < 1)
	{
		if (d->argc > 1 && d->argc<= 4)
			sort3(d); // 6 for 100, 10 for 500
		if (d->argc > 4 && d->argc<= 6)
			sort5(d);
		if (d->argc > 6 && d->argc <= 495)
			push_tob_lim(d, d->argc/4); // 6 for 100, 10 for 500
		if (d->argc > 495)
			push_tob_lim(d, d->argc/12); // 6 for 100, 10 for 500
		push_toa_lim(d, 2);
	}
	return (0);
}
