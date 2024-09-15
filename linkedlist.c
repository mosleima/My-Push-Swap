/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:23:56 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 16:52:26 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*create_node(int data)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
		return (NULL);
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = data;
	temp->index = -1;
	temp->push_cost = 0;
	temp->target_node = NULL;
	return (temp);
}

void	add_node_at_head(t_node **head, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

t_node	*get_tail(t_node *list)
{
	t_node	*curr;

	if (list == NULL)
		return (NULL);
	curr = list;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	add_tail(t_node **head, int data)
{
	t_node	*temp;
	t_node	*tail;

	temp = create_node(data);
	if (!temp)
		exit(1);
	if (*head == NULL)
		*head = temp;
	else
	{
		tail = get_tail(*head);
		tail->next = temp;
		temp->prev = tail;
	}
}

void	del_head(t_node **s)
{
	t_node	*current;

	if (*s == NULL)
		return ;
	current = *s;
	*s = (*s)->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	free(current);
}
