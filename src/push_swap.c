/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 18:14:57 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 21:32:27 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "./stack.c"
// #include "./ft_digits_ft.c"
// #include "./operations.c"
// #include "./algorythm.c"
// #include "./service.c"
// #include "./del.c"
#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	struct s_data data;

	if (argc < 2)
		return (1);

	data.argc = argc;
	data.argv = argv;
	if (sorted_int(&data) < 0)
		return (error());
	if (check_input(&data) < 0)
		return (error());
	data.indmid = (argc + argc % 2) / 2;
	get_arg_stack(&data);
	sort(&data);
	printlist(&data);
	return (0);
}
