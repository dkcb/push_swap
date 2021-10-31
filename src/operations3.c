/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 18:25:33 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/30 21:34:26 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(struct s_d *d)
{
	ft_putstring("rrr\n");
	if (d->ha)
		d->ha = d->ha->pr;
	if (d->hb)
		d->hb = d->hb->pr;
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
