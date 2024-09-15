/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:41:44 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 16:45:13 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

void	handle_error(t_node **head, char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	if (head && *head)
	{
		while (*head)
			del_head(head);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	update_indices(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

int	check_duplicates(t_node *head)
{
	t_node	*current;
	t_node	*runner;

	while (head)
	{
		current = head;
		runner = head->next;
		while (runner)
		{
			if (current->data == runner->data)
				return (1);
			runner = runner->next;
		}
		head = head->next;
	}
	return (0);
}
