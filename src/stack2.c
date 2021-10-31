/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/31 18:57:06 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance(struct s_node *head, int index, int r, int rr)
{
	struct s_node	*n;

	if (head)
	{
		n = head;
		while (n->i != index && r <= size_stack(&head))
		{
			n = n->nx;
			r++;
		}
	}
	if (head)
	{
		n = head;
		while (n->i != index && rr <= r && rr <= size_stack(&head))
		{
			n = n->pr;
			rr++;
		}
	}
	if (r <= rr)
		return (r);
	return (-1 * rr);
}

int	distance_range(struct s_node *head, int min, int max)
{
	int	cd;
	int	i;
	int	maxdistr;
	int	maxdistrr;

	i = 0;
	maxdistr = 2147483645;
	maxdistrr = -2147483645;
	while (i + min < max)
	{
		cd = distance(head, i + min, 0, 0);
		if (cd > 0 && cd < maxdistr)
			maxdistr = cd;
		else if (cd < 0 && cd > maxdistrr)
			maxdistrr = cd;
		else if (cd == 0)
			return (0);
		i++;
	}
	if (maxdistrr * -1 >= maxdistr)
		return (maxdistr);
	return (maxdistrr);
}

int	size_stack(struct s_node **head)
{
	int				i;
	struct s_node	*current;

	if (!head || !head[0])
		return (0);
	i = 1;
	current = head[0];
	while (current->nx != head[0])
	{
		current = current->nx;
		i++;
	}
	return (i);
}

int	ordered(struct s_node *head)
{
	struct s_node	*n;

	if (head)
	{
		n = head;
		if (n->data > n->nx->data)
			return (0);
		while (n->nx != head)
		{
			if (n->data > n->nx->data)
				return (0);
			n = n->nx;
		}
	}
	return (1);
}
