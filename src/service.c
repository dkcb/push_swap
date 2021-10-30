/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   service.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:11:37 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 21:23:59 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	assign(struct s_d *d)
{
	d->fun_ptr_arr['s' + 'a'] = &sa;
	d->fun_ptr_arr['s' + 'b'] = &sb;
	d->fun_ptr_arr['s' + 's'] = &ss;
	d->fun_ptr_arr['p' + 'a'] = &pb;
	d->fun_ptr_arr['p' + 'b'] = &pb;
	d->fun_ptr_arr['r' + 'a'] = &ra;
	d->fun_ptr_arr['r' + 'b'] = &rb;
	d->fun_ptr_arr['r' + 'r'] = &rr;
	d->fun_ptr_arr['r' + 'r' + 'a'] = &rra;
	d->fun_ptr_arr['r' + 'r' + 'b'] = &rrb;
	d->fun_ptr_arr['r' + 'r' + 'r'] = &rrr;
}

int	ft_exit(struct s_d *d, int fl)
{
	struct s_node	*n;
	void			*p;

	p = d->ha;
	while (d->ha)
	{
		n = d->ha->nx;
		if (n != p)
			free (d->ha);
		else
			break ;
		d->ha = n;
	}
	p = d->hb;
	while (d->hb)
	{
		n = d->hb->nx;
		if (n != p)
			free (d->hb);
		else
			break ;
		d->hb = n;
	}
	if (d->intlist)
		free(d->intlist);
	if (d->sorted)
		free(d->sorted);
	if (fl < 0)
		ft_putstring("Error\n");
	return (0);
}

int	check_input(struct s_d *d, int i, int i2)
{
	while (i < d->argc)
	{
		if (d->sorted[i] == d->sorted[i - 1])
			return (-1);
		i++;
	}
	i--;
	while (i > 0)
	{
		i2 = 0;
		while (d->a[i][i2] != '\0')
		{
			if ((!ft_isdigit(d->a[i][i2])
				&& d->a[i][i2] != ' ' && d->a[i][i2] != '-')
				|| (d->a[i][i2] == '-' && !ft_isdigit(d->a[i][i2 + 1])))
				return (-1);
			i2++;
		}
		i--;
	}
	return (0);
}
