/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:42:56 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/10 18:06:37 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_node *a, t_node *b)
{
	long	best_match_index;
	t_node	*curr_b;
	t_node	*target_node;

	while (a)
	{
		best_match_index = LONG_MIN;
		target_node = NULL;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->data < a->data && curr_b->data > best_match_index)
			{
				best_match_index = curr_b->data;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (!target_node)
			a->target_node = max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	long	best_match_index;
	t_node	*curr_a;
	t_node	*target_node;

	while (b)
	{
		best_match_index = LONG_MAX;
		target_node = NULL;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->data > b->data && curr_a->data < best_match_index)
			{
				best_match_index = curr_a->data;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (!target_node)
			b->target_node = min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
