/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 18:14:57 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 21:05:02 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "./stack.c"
// #include "./ft_digits_ft.c"
// #include "./operations.c"
// #include "./algorythm.c"
// #include "./service.c"
// #include "./del.c"
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_d	d;

	if (argc < 2)
		return (1);
	d.argc = argc;
	d.a = argv;
	if (sorted_int(&d) < 0)
		return (ft_exit(&d, -1));
	if (check_input(&d, 1, 0) < 0)
		return (ft_exit(&d, -1));
	assign(&d);
	get_arg_stack(&d);
	sort(&d);
	ft_exit(&d, 1);
	return (0);
}
