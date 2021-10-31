/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 18:14:57 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/31 19:12:03 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_d	d;

	if (argc < 2)
		return (1);
	d.argc = argc;
	d.a = argv;
	if (unsorted_int(&d, 0) < 0)
		return (ft_exit(&d, -1));
	if (sorted_int(&d, 0, 0) < 0)
		return (ft_exit(&d, -1));
	if (check_input(&d, 1, 0) < 0)
		return (ft_exit(&d, -1));
	assign(&d);
	get_arg_stack(&d);
	sort(&d);
	ft_exit(&d, 1);
	return (0);
}
