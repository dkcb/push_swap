/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/29 22:06:16 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance(struct s_node *head, int index)
{
	struct s_node	*n;
	int				r;
	int				rr;
	int				size;

	r = 0;
	rr = 0;
	size = size_stack(&head);
	if (head)
	{
		n = head;
		while (n->i != index && r <= size)
		{
			n = n->nx;
			r++;
		}
	}
	if (head)
	{
		n = head;
		while (n->i != index && rr <= r && rr <= size)
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
		cd = distance(head, i + min);
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

int	get_index(struct s_d *d, int num)
{
	int	i;

	i = 0;
	while (i < d->argc - 1)
	{
		if (d->sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	sorted_int(struct s_d *d)
{
	int	*intlist;
	int	*sintlist;
	int	i;
	int	tmp;

	i = 0;
	intlist = malloc(sizeof(int) * d->argc);
	sintlist = malloc(sizeof(int) * d->argc);
	if (!sintlist || !intlist)
		return (-1);
	while (i < d->argc - 1)
	{
		if (val(d->a[i + 1]) > 2147483647 || val(d->a[i + 1]) < -2147483648)
			return (-1);
		intlist[i] = (int)val(d->a[i + 1]);
		sintlist[i] = intlist[i];
		i++;
	}
	d->intlist = intlist;
	i = 0;
	while (i < d->argc - 1)
	{
		if ((sintlist[i] > sintlist[i + 1]) && i < d->argc - 2)
		{
			tmp = sintlist[i];
			sintlist[i] = sintlist[i + 1];
			sintlist[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	d->sorted = sintlist;
	return (0);
}

int	get_arg_stack(struct s_d *d)
{
	int				i;
	struct s_node	*previous;
	struct s_node	*current;
	struct s_node	*next;

	i = 0;
	current = (struct s_node *)malloc(sizeof(struct s_node));
	while (i < d->argc - 1)
	{
		next = (struct s_node *)malloc(sizeof(struct s_node));
		current->nx = next;
		current->pr = previous;
		current->data = d->intlist[i];
		current->i = get_index(d, current->data);
		previous = current;
		if (i == 0)
			d->ha = current;
		current = next;
		i++;
	}
	free (current);
	d->hb = NULL;
	previous->nx = d->ha;
	d->ha->pr = previous;
	return (i);
}

struct s_node	*cut(struct s_node **head, int pos)
{
	struct s_node	*current;

	current = head[0];
	if (size_stack(&head[0]) < 2)
	{
		head[0] = NULL;
		return (current);
	}
	if (pos == 0)
		head[0] = head[0]->nx;
	while (pos > 0)
	{
		current = current->nx;
		pos--;
	}
	current->nx->pr = current->pr;
	current->pr->nx = current->nx;
	return (current);
}

struct s_node	*paste(struct s_node **head, struct s_node *node, int pos)
{
	struct s_node	*current;

	current = head[0]->pr;
	if (pos == 0)
		head[0] = node;
	while (pos > 0)
	{
		current = current->nx;
		pos--;
	}
	current->nx->pr = node;
	node->nx = current->nx;
	current->nx = node;
	node->pr = current;
	return (current);
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
