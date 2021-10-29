/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 21:34:24 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int distance(struct s_node *head, int index)
{
	struct s_node	*n;
	int r = 0;
	int rr = 0;
	int size = size_stack(&head);

	if (head)
	{
		n = head;
		while (n->index != index && r <= size)
		{
			n = n->next;
			r++;
		}
	}
	if (head)
	{
		n = head;
		while (n->index != index && rr <= r && rr <= size)
		{
			n = n->prev;
			rr++;
		}
	}
	if (r <= rr)
		return (r);
	return (-1 * rr);
}

int distance_range(struct s_node *head, int min, int max)
{
	int	cd;
	int	i = 0;
	int	maxdistr = 2147483647;
	int	maxdistrr = -2147483648;

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

int	get_index(struct s_data *data, int num)
{
	int i;

	i = 0;
	while(i < data->argc - 1)
	{
		if (data->sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int sorted_int(struct s_data *data)
{
	int *intlist;
	int *sintlist;
	int i;
	int tmp;

	i = 0;

	intlist = malloc(sizeof(int) * data->argc - 1);
	sintlist = malloc(sizeof(int) * data->argc - 1);
	if(!sintlist || !intlist)
		return (-1);
	while (i < data->argc - 1)
	{
		if (get_val(data->argv[i + 1]) > 2147483647 || get_val(data->argv[i + 1]) < -2147483648)
			return (-1);
		intlist[i] = (int)get_val(data->argv[i + 1]);
		sintlist[i] = intlist[i];
		i++;
	}
	data->intlist = intlist;
	i = 0;
	while (i < data->argc - 1)
	{
		if ((sintlist[i] > sintlist[i + 1]) && i < data->argc - 2)
		{
			tmp = sintlist[i];
			sintlist[i] = sintlist[i + 1];
			sintlist[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	data->sorted = sintlist;
	return (0);
}

int get_arg_stack(struct s_data *data)
{
	int i = 0;
	struct	s_node *previous;
	struct	s_node *current;
	struct	s_node *next;

	current = (struct s_node *)malloc(sizeof(struct s_node));
	while (i < data->argc - 1)
	{
		next = (struct s_node *)malloc(sizeof(struct s_node));
		current->next = next;
		current->prev = previous;
		current->data = data->intlist[i];
		current->index = get_index(data, current->data);
		previous = current;
		if (i == 0)
			data->heada = current;
		current = next;
		i++;
	}
	data->size_a = data->argc;
	data->size_b = 0;
	free (current);
	data->headb = NULL;
	previous->next = data->heada;
	data->heada->prev = previous;
	return (i);
}

struct s_node *cut (struct s_node **head, int pos)
{
	struct s_node *current;

	current = head[0];
	if (size_stack(&head[0]) < 2)
	{
		head[0] = NULL;
		return (current);
	}
	if (pos == 0)
		head[0] = head[0]->next;
	while (pos > 0)
	{
		current = current->next;
		pos--;
	}
	current->next->prev = current->prev;
	current->prev->next = current->next;
	return (current);
}

struct s_node *paste (struct s_node **head, struct s_node *node, int pos)
{
	struct s_node *current;

	current = head[0]->prev;
	if (pos == 0)
		head[0] = node;
	while (pos > 0)
	{
		current = current->next;
		pos--;
	}
	current->next->prev = node;
	node->next = current->next;
	current->next = node;
	node->prev = current;
	return (current);
}

int	size_stack(struct s_node **head)
{
	int	i;
	struct s_node *current;

	if (!head || !head[0])
		return (0);
	i = 1;
	current = head[0];
	while (current->next != head[0])
	{
		current = current->next;
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
		if (n->data > n->next->data)
			return (0);
		while (n->next != head)
		{
			if (n->data > n->next->data)
				return (0);
			n = n->next;
		}
	}
	return (1);
}
