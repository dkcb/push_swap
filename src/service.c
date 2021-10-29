/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   service.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:11:37 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/22 16:44:20 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_exit(struct s_data *data, int fl)
{
	struct s_node	*n;
	void *p;

	p = data->heada;
	while (data->heada)
	{
		n = data->heada->next;
		if (n != p)
			free (data->heada);
		else
			break ;
		data->heada = n;
	}
	p = data->headb;
	while (data->headb)
	{
		n = data->headb->next;
		if (n != p)
			free (data->headb);
		else
			break ;
		data->headb = n;
	}
	if (data->intlist)
		free(data->intlist);
	if (data->sorted)
		free(data->sorted);
	if (fl < 0)
		ft_putstring("Error\n");
	return (0);
}

int	check_input(struct s_data *data)
{
	int	i;
	int	i2;

	i = 1;
	i2 = 0;
	while (i < data->argc)
	{
		if (data->sorted[i] == data->sorted[i - 1])
			return (-1);
		i++;
	}
	i--;
	while (i > 0)
	{
		i2 = 0;
		while (data->argv[i][i2] != '\0')
		{
			if ((!ft_isdigit(data->argv[i][i2]) && data->argv[i][i2] != ' ' && data->argv[i][i2] != '-') 
				|| (data->argv[i][i2] == '-' && !ft_isdigit(data->argv[i][i2 + 1])))
				return (-1);
			i2++;
		}
		i--;
	}
	return (0);
}
