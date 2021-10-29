/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   service.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:11:37 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/29 21:52:18 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_exit(struct s_d *d, int fl)
{
	struct s_node	*n;
	void *p;

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

int	check_input(struct s_d *d)
{
	int	i;
	int	i2;

	i = 1;
	i2 = 0;
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
		while (d->argv[i][i2] != '\0')
		{
			if ((!ft_isdigit(d->argv[i][i2]) && d->argv[i][i2] != ' ' && d->argv[i][i2] != '-') 
				|| (d->argv[i][i2] == '-' && !ft_isdigit(d->argv[i][i2 + 1])))
				return (-1);
			i2++;
		}
		i--;
	}
	return (0);
}
