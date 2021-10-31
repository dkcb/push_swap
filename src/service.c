/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   service.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:11:37 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/31 19:12:08 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	d->ha->pr->nx = NULL;
	while (d->ha)
	{
		n = d->ha->nx;
		free (d->ha);
		d->ha = n;
	}
	if (d->intlist)
		free(d->intlist);
	if (d->sintlist)
		free(d->sintlist);
	if (fl < 0)
		ft_putstring("Error\n");
	return (0);
}

int	check_input(struct s_d *d, int i, int i2)
{
	while (i < d->argc)
	{
		if (d->sintlist[i] == d->sintlist[i - 1])
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
