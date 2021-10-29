/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorythm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 22:34:54 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_swap_hab_tob(struct s_data* data)
{
	if (data->headb && data->headb->index < data->headb->next->index)
	{
		sb(data);
		return (1);
	}
	return (0);
}

int	check_swap_hab_toa(struct s_data* data)
{
	if (data->heada && data->heada->index > data->heada->next->index)
	{
		sa(data);
		return(1);
	}
	return (0);
}

int	sort3(struct s_data* data)
{
	while (data->heada && ordered(data->heada) < 1)
	{
		if (data->heada && data->heada->index > data->heada->next->index && data->heada->index < data->heada->next->next->index)
			sa(data);
		else if (data->heada && data->heada->index > data->heada->next->index)
			ra(data);
		else if (data->heada && data->heada->next->index > data->heada->next->next->index)
			rra(data);
	}
	return (0);
}

int	sort5(struct s_data* data)
{
	while (data->heada && ordered(data->heada) < 1)
	{
		while (size_stack(&data->heada) > 3)
		{
			while (distance_range(data->heada, 0, data->argc - 4) > 0)
				ra(data);
			while (distance_range(data->heada, 0, data->argc - 4) < 0)
				rra(data);
			pb(data);
		}
		sort3(data);
		if (data->headb && data->headb->index < data->headb->next->index)
			sb(data);
		while (data->headb && size_stack(&data->headb) > 0)
			pa(data);
	}
	return (0);
}

int push_tob_lim(struct s_data* data, int gap)
{
	int dcn;
	int cnt = 0;
	int	treshhold = gap;
	
	while (data->heada && size_stack(&data->heada) > 0)
	{
		dcn = distance_range(data->heada, treshhold - gap, treshhold);
		while (data->heada && data->heada->index < treshhold && size_stack(&data->heada) > 0 && cnt < gap)
		{
			pb(data);
			cnt++;
			if (cnt >= gap)
			{
				cnt = 0;
				treshhold += gap;
			}
			check_swap_hab_tob(data);
		}
		dcn = distance_range(data->heada, treshhold - gap, treshhold);
		if (size_stack(&data->heada) > 0 && check_swap_hab_tob(data) < 1)
		{
			// if (dcn < 0) //comm 10000
			// 	rra(data);
			// if (dcn > 0)
				ra(data);
		}
		if (cnt >= gap)
		{
			cnt = 0;
			treshhold += gap;
		}
	}
	return (0);
}

int push_toa_lim(struct s_data* data, int gap)
{
	int dcn;
	int cnt = 0;
	int	treshhold = data->argc - gap - 1;
	
	while (data->headb && size_stack(&data->headb) > 0)
	{
		// check_swap_hab_toa(data);
		dcn = distance_range(data->headb, treshhold , treshhold + gap);
		while (data->headb && data->headb->index >= treshhold && size_stack(&data->headb) > 0 && cnt < gap)
		{
			pa(data);
			cnt++;
			if (cnt >= gap)
			{
				cnt = 0;
				treshhold -= gap;
			}
			check_swap_hab_toa(data);
		}
		dcn = distance_range(data->headb, treshhold, treshhold + gap);
		if (size_stack(&data->headb) > 0 && check_swap_hab_toa(data) < 1)
		{
			if (dcn < 0)
				rrb(data);
			else if (dcn > 0)
				rb(data);
		}
		if (cnt >= gap)
		{
			cnt = 0;
			treshhold -= gap;
		}
	}
	return (0);
}

int	sort(struct s_data* data)
{
	if (data->heada && ordered(data->heada) < 1)
	{
		if (data->argc > 1 && data->argc<= 4)
			sort3(data); // 6 for 100, 10 for 500
		if (data->argc > 4 && data->argc<= 6)
			sort5(data);
		if (data->argc > 6 && data->argc <= 495)
			push_tob_lim(data, data->argc/4); // 6 for 100, 10 for 500
		if (data->argc > 495)
			push_tob_lim(data, data->argc/12); // 6 for 100, 10 for 500
		push_toa_lim(data, 2);
	}
	return (0);
}
