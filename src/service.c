/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   service.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:11:37 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 20:21:37 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error(void)
{
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

int	ft_putstring(char *s)
{
	int	i = 0;

	while (s[i] && s[i] != '\0')
		i++;
	write(1,&s[0], i);
	return (0);
}
