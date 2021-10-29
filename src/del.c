/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/21 21:22:34 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void printlist(struct s_data* data)
{
	struct s_node *current;
	
	printf("A: ");
	if (data->heada)
	{
		current = data->heada;
		printf("%d ", current->data);
		current = current->next;
		while (current != data->heada)
		{
			printf(" %d ", current->data);
			current = current->next;
		}
	}
	printf ("\n");
	printf("B: ");
	if (data->headb)
	{
		current = data->headb;
		printf("%d ", current->data);
		current = current->next;
		while (current != data->headb)
		{
			printf(" %d ", current->data);
			current = current->next;
		}
	}
	printf ("\n");
}
