/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digits_ft.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 20:46:31 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 20:37:45 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit (char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	get_val(char *s)
{
	int		i;
	long long	pwr;
	long long	res;
	long long	neg;

	neg = 1;
	i = 0;
	res = 0;
	pwr = 1;
	while (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
		i++;
	i--;
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res + (s[i] - '0') * pwr;
		pwr = pwr * 10;
		i--;
	}
	// printf ("RES:%d\n", res);
	// if (res > 2147483647)
	// 	return (0);
	return (res * neg);
}
